#include <gtest/gtest.h>
#include <mips/core.hpp>
#include <mips/decoder/instruction_decoder.hpp>
#include <mips/instructions/instruction_I.hpp>
#include <iostream>

using namespace MIPS;

TEST(InstructionDecoder, getInstructionInfo) {
    instruction_t instruction = 0x799a;
    InstructionDecoder decoder;
    // InstructionI *emu_instruction = (InstructionI*) decoder.decode(instruction);
    ASSERT_EQ(decoder.getOPCode(instruction), 1);
    ASSERT_EQ(decoder.getRd(instruction), 7);
    ASSERT_EQ(decoder.getFunct(instruction), 6);
    ASSERT_EQ(decoder.getRs(instruction), 3);
    ASSERT_EQ(decoder.getRt(instruction), 2);
    // emu_instruction->execute();
}
