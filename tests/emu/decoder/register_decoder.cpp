#include <gtest/gtest.h>
#include <mips/core.hpp>
#include <mips/decoder/register_decoder.hpp>
#include <mips/instructions/register_instruction.hpp>
#include <iostream>

using namespace MIPS;

TEST(register_decoder, getOpCode) {
    instruction32_t instruction = 0xac000000;
    RegisterInstructionDecoder decoder;
    RegisterInstruction *emu_instruction = (RegisterInstruction*) decoder.decode(instruction);
    ASSERT_EQ(2, 3);
}
