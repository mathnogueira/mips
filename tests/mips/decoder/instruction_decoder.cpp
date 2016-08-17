#include <gtest/gtest.h>
#include <mips/core.hpp>
#include <mips/decoder/instruction_decoder.hpp>
#include <mips/instructions/instruction_I.hpp>
#include <mips/memory/register_bank.hpp>
#include <mips/units/control.hpp>
#include <iostream>

using namespace MIPS;

TEST(InstructionDecoder, getInstructionInfo) {
	ControlUnit cu;
	RegisterBank bank(cu);
    instruction_t instruction = 0x799a;
    InstructionDecoder decoder(bank);
    // InstructionI *emu_instruction = (InstructionI*) decoder.decode(instruction);
    ASSERT_EQ(decoder.getOPCode(instruction), 1);
    ASSERT_EQ(decoder.getRd(instruction), 7);
    ASSERT_EQ(decoder.getFunct(instruction), 6);
    ASSERT_EQ(decoder.getRs(instruction), 3);
    ASSERT_EQ(decoder.getRt(instruction), 2);
    // emu_instruction->execute();
}

TEST(InstructionDecoder, getOffset) {
	ControlUnit cu;
	RegisterBank bank(cu);
    InstructionDecoder decoder(bank);
    instruction_t instruction = 0x1cf3;
    ASSERT_EQ(decoder.getOffset(instruction, 8), 0x00f3);
    ASSERT_EQ(decoder.getOffset(instruction, 11), 0x04f3);
    ASSERT_NE(decoder.getOffset(instruction, 10), 0x01f3);
}
