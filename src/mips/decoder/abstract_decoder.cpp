#include <mips/decoder/abstract_decoder.hpp>
#include <cstdlib>

using namespace MIPS;

InstructionDecoder::InstructionDecoder() {}

InstructionDecoder::~InstructionDecoder() {}

Instruction* InstructionDecoder::decode(instruction_t instruction) {
    return NULL;
}

bit8_t InstructionDecoder::getOPCode(instruction_t instruction) {
    // shift de 26 casas pra direita: pega as 6 casas mais significativas
    return instruction >>= 26;
}
