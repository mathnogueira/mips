#include <mips/decoder/decoder_finder.hpp>
#include <cstdlib>

using namespace MIPS;

DecoderFinder::DecoderFinder() {}

DecoderFinder::~DecoderFinder() {}

InstructionDecoder* DecoderFinder::find(instruction32_t instruction) {
    bit8_t opcode = getOPCode(instruction);
    if (opcode == 43) {
        DEBUG("ADD");
    } else {
        DEBUG("SUB");
    }
    return NULL;
}
