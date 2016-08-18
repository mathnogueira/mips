#include <mips/cpu.hpp>
#include <mips/memory/memory.hpp>
#include <mips/memory/register_bank.hpp>
#include <mips/util/logger.hpp>
#include <cstdio>

using namespace MIPS;

CPU::CPU(struct options &opt) : options(opt) {
	aluFlags = {0, 0, 0, 0};
	controlUnit = new ControlUnit;
	memory = new Memory(*controlUnit);
	bank = new RegisterBank(*controlUnit);
    instructionFinder = new InstructionFinder(*memory, *bank);
    instructionDecoder = new InstructionDecoder(*bank, *memory);
	instructionDecoder->setALUFlags(&aluFlags);
}

CPU::~CPU() {
    delete memory;
    delete bank;
    delete controlUnit;
    delete instructionFinder;
    delete instructionDecoder;
}

void CPU::loadProgram(const char *program) {
    FILE *fp = fopen(program, "rb");
    size_t size;
    bit16_t instruction;
    // Lê os primeiros 8 bytes do arquivo para descobrir o número de
    // instruções que o programa tem
    fread(&size, sizeof(size_t), 1, fp);
    // Inicializa a memória de instruções
    memory->setInstructionSize(size);
	// Carrega memória de dados
	memory->setDataSize(64 * 1024);
	controlUnit->memWrite = true;
    // Insere todas as instruções na memória de instruções
    for (size_t i = 0; i < size; ++i) {
        fread(&instruction, sizeof(bit16_t), 1, fp);
        memory->write(instruction, i, 0);
    }
	controlUnit->memWrite = false;
    fclose(fp);
}

void CPU::execute() {
    do {
        // Busca a instrução e incrementa o PC
        instruction_t instruction = instructionFinder->getNext();
        // Se for instrução de HALT, para a execução
        if (instruction == 0x2fff)
            break;
        bit16_t result = 0;
        // Decodifica a instrução
        Instruction *instructionObject = instructionDecoder->decode(instruction);
        // Executa a instrução
        // Atualiza as flags de controle
        instructionObject->updateControl(*controlUnit);
		instructionObject->setALUFlags(aluFlags);
        result = instructionObject->execute();
		// Verifica se a instrução era um jump, e se haverá o desvio
		if (controlUnit->jump && result == 1) {
			bit8_t funct = (instruction >> 12) & 3;
			FORMAT_DEBUG("FUNCT %d\n", funct);
			if (funct == 2) {
				// JUMP
				// Atualiza o PC
				bank->getPC()->put(instructionDecoder->getOffset(instruction, 12));
			}
			controlUnit->regwrite = false;
		}
		// Verifica se é um branch
		if (controlUnit->branch && result == 1) {
			// Atualiza o PC
			Register *pc = bank->getPC();
			FORMAT_DEBUG("PC: %d\n", pc->get());
			FORMAT_DEBUG("Offset: %d\n", instructionDecoder->getOffset(instruction, 8));
			pc->put(pc->get() + instructionDecoder->getOffset(instruction, 8));
			controlUnit->regwrite = false;
		}
        // Pega o índice do registrador de destino
        bit8_t regdst;
		if (controlUnit->regDst)
			regdst = instructionDecoder->getRd(instruction);
		else
			regdst = instructionDecoder->getRt(instruction);
        // Coloca o valor no banco de registradores
        // O valor só será escrito se a flag do controle for definida como true
        bank->write(result, regdst);
		// Reseta as flags
		controlUnit->reset();
		// Imprime o relatório da instrução executada
		if (options.screen)
			Logger::screen(*bank, aluFlags, instruction);
		if (options.pause)
			getchar();
    } while (true);
	// Imprime o dump de memória
	if (options.dump)
		Logger::dump(*memory, options.dump_start, options.dump_size);
}
