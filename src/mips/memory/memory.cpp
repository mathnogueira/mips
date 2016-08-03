#include <mips/memory/memory.hpp>
#include <mips/memory/memory_exception.hpp>
#include <cstdlib>

using namespace MIPS;

Memory::Memory() {
    instructions = NULL;
    data = NULL;
}

Memory::~Memory() {
    if (instructions)
        delete[] instructions;
    if (data)
        delete[] data;
}

void Memory::setInstructionSize(size_t size) {
    if (instructions)
        delete[] instructions;
    instructions = new bit16_t[size];
    instructionsSize = size;
}

void Memory::setDataSize(size_t size) {
    if (data)
        delete[] data;
    data = new bit16_t[size];
    dataSize = size;
}

void Memory::write(bit16_t data, bit32_t offset, bit8_t iOrD) {
    bit16_t *memory;
    bit32_t size;
    if (iOrD) {
        memory = this->data;
        size = dataSize;
    } else {
        memory = this->instructions;
        size = instructionsSize;
    }
    // Verifica se offset é válido
    if (offset < 0 || offset >= size) {
        std::cout << offset << std::endl;
        std::cout << size << std::endl;
        // Não pode escrever na memória
        // Gera erro
        throw MemoryException("Indice de memória não pode ser acessado!");
    }
    // Escreve na memória
    memory[offset] = data;
}

bit16_t Memory::read(bit32_t offset, bit8_t iOrD) {
    bit16_t *memory;
    bit32_t size;
    if (iOrD) {
        memory = this->data;
        size = dataSize;
    } else {
        memory = this->instructions;
        size = instructionsSize;
    }
    // Verifica se offset é válido
    if (offset < 0 || offset >= size) {
        std::cout << offset << std::endl;
        std::cout << size << std::endl;
        // Não pode escrever na memória
        // Gera erro
        throw MemoryException("Indice de memória não pode ser acessado!");
    }
    return memory[offset];
}
