#include <gtest/gtest.h>
#include <mips/core.hpp>
#include <mips/decoder/register_decoder.hpp>
#include <mips/instructions/register_instruction.hpp>
#include <iostream>

using namespace MIPS;

TEST(register_decoder, getOpCode) {
    instruction_t instruction = 0xac000000;
    RegisterInstructionDecoder decoder;
    RegisterInstruction *emu_instruction = (RegisterInstruction*) decoder.decode(instruction);
}
