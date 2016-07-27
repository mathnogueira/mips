#include <mips/decoder/decoder_finder.hpp>
#include <mips/instructions/map.hpp>
#include <mips/decoder/register_decoder.hpp>

using namespace MIPS;

DecoderFinder::DecoderFinder() {}

DecoderFinder::~DecoderFinder() {}

Instruction* DecoderFinder::decode(instruction_t instruction) {
    InstructionDecoder* decoder = find(instruction);
    return NULL;
}

InstructionDecoder* DecoderFinder::find(instruction_t instruction) {
    bit8_t opcode = getOPCode(instruction);
    InstructionDecoder* decoder = NULL;
    if (Instruction_isR(opcode)) {
        decoder = new RegisterInstructionDecoder;
    } else if (Instruction_isI(opcode)){
        decoder = NULL;
    } else {
        decoder = NULL;
    }
    return decoder;
}
