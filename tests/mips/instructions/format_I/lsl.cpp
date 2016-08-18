#include <gtest/gtest.h>
#include <mips/instructions/format_I/lsl.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(LslInstruction, positiveNumber) {
	Register rs("s0");
	LslInstruction lsl(0, &rs, NULL, 0, 0);
	struct ALUFlags flags;
	lsl.setALUFlags(flags);
	rs.put(23);
	ASSERT_EQ(lsl.execute(), 46);
}

TEST(LslInstruction, positiveNumberOdd) {
	Register rs("s0");
	LslInstruction lsl(0, &rs, NULL, 0, 0);
	struct ALUFlags flags;
	lsl.setALUFlags(flags);
	rs.put(9);
	ASSERT_EQ(lsl.execute(), 18);
}

TEST(LslInstruction, NegativeNumber) {
	Register rs("s0");
	LslInstruction lsl(0, &rs, NULL, 0, 0);
	struct ALUFlags flags;
	lsl.setALUFlags(flags);
	rs.put(-6);
	ASSERT_EQ(lsl.execute(), -12);
}

TEST(LslInstruction, NegativeNumberOdd) {
	Register rs("s0");
	LslInstruction lsl(0, &rs, NULL, 0, 0);
	struct ALUFlags flags;
	lsl.setALUFlags(flags);
	rs.put(-10);
	ASSERT_EQ(lsl.execute(), -20);
}
