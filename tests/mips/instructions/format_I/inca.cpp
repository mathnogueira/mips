#include <gtest/gtest.h>
#include <mips/instructions/format_I/inca.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(IncaInstruction, incaPositive) {
	Register rs("s0");
	IncaInstruction inca(0, &rs, NULL, 0, 0);
	struct ALUFlags flags;
	inca.setALUFlags(flags);
	rs.put(3);
	ASSERT_EQ(inca.execute(), 4);
}

TEST(IncaInstruction, incaNegative) {
	Register rs("s0");
	IncaInstruction inca(0, &rs, NULL, 0, 0);
	struct ALUFlags flags;
	inca.setALUFlags(flags);
	rs.put(-31200);
	ASSERT_EQ(inca.execute(), -31199);
}
