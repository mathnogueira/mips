#include <mips/cpu.hpp>
#include <mips/memory/memory.hpp>
#include <mips/memory/register_bank.hpp>
#include <cstdio>

using namespace MIPS;

CPU::CPU() {
    memory = new Memory;
    bank = new RegisterBank;
    controlUnit = new ControlUnit;
    instructionFinder = new InstructionFinder(*memory, *bank);
    instructionDecoder = new InstructionDecoder(*bank);
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
    // Insere todas as instruções na memória de instruções
    for (size_t i = 0; i < size; ++i) {
        fread(&instruction, sizeof(bit16_t), 1, fp);
        memory->write(instruction, i, 0);
    }
    fclose(fp);
}

void CPU::execute() {
    do {
        // Busca a instrução e incrementa o PC
        instruction_t instruction = instructionFinder->getNext();
        // Se for instrução de HALT, para a execução
        if (instruction == 0x2fff)
            return;
        bit16_t result = 0;
        // Decodifica a instrução
        Instruction *instructionObject = instructionDecoder->decode(instruction);
        // Executa a instrução
        // Atualiza as flags de controle
        instructionObject->updateControl(*controlUnit);
        result = instructionObject->execute();
		// Verifica se a instrução era um jump, e se haverá o desvio
		if (controlUnit->jump && result == 1) {
			// Atualiza o PC
			// pc = (pc+1) + offset
			bank->getPC()->put(instructionDecoder->getOffset(instruction, 12));
		}
        // Pega o índice do registrador RD
        bit8_t rd = instructionDecoder->getRd(instruction);
        // Coloca o valor no banco de registradores
        // O valor só será escrito se a flag do controle for definida como true
        bank->write(result, rd);
		//
    } while (true);
}
