#include <gtest/gtest.h>
#include <mips/core.hpp>
#include <mips/decoder/register_decoder.hpp>
#include <mips/instructions/instruction_I.hpp>
#include <iostream>

using namespace MIPS;

TEST(register_decoder, getOpCode) {
    instruction_t instruction = 0xac000000;
    InstructionIDecoder decoder;
    InstructionI *emu_instruction = (InstructionI*) decoder.decode(instruction);
}
