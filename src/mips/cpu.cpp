#include <mips/cpu.hpp>
#include <mips/memory/memory.hpp>
#include <mips/memory/register_bank.hpp>
#include <mips/decoder/decoder_finder.hpp>
#include <cstdio>

using namespace MIPS;

CPU::CPU() {
    memory = new Memory;
    bank = new RegisterBank;
    decoder = new DecoderFinder;
}

CPU::~CPU() {}

void CPU::loadProgram(const char *program) {
    FILE *fp = fopen(program, "rb");
    size_t size;
    bit16_t instruction;
    // Lê os primeiros 4 bytes do arquivo para descobrir o número de
    // instruções que o programa tem
    fread(&size, sizeof(size_t), 1, fp);
    // Inicializa a memória de instruções
    memory->setInstructionSize(size);
    // Insere todas as instruções na memória de instruções
    for (size_t i = 0; i < size; ++i) {
        fread(&instruction, sizeof(bit16_t), 1, fp);
    }
    fclose(fp);
}
