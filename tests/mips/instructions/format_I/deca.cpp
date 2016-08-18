#include <gtest/gtest.h>
#include <mips/instructions/format_I/deca.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(DecaInstruction, decaPositive) {
	Register rs("s0");
	DecaInstruction deca(0, &rs, NULL, 0, 0);
	struct ALUFlags flags;
	deca.setALUFlags(flags);
	rs.put(3);
	ASSERT_EQ(deca.execute(), 2);
}

TEST(DecaInstruction, decaNegative) {
	Register rs("s0");
	DecaInstruction deca(0, &rs, NULL, 0, 0);
	struct ALUFlags flags;
	deca.setALUFlags(flags);
	rs.put(-31200);
	ASSERT_EQ(deca.execute(), -31201);
}
