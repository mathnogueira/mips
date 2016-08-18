#include <gtest/gtest.h>
#include <mips/instructions/format_I/lsr.hpp>
#include <mips/memory/register.hpp>
#include <mips/debug.hpp>

using namespace MIPS;

TEST(LsrInstruction, positiveNumber) {
	Register rs("s0");
	LsrInstruction lsr(0, &rs, NULL, 0, 0);
	struct ALUFlags flags;
	lsr.setALUFlags(flags);
	rs.put(2);
	ASSERT_EQ(lsr.execute(), 1);
}

TEST(LsrInstruction, positiveNumberOdd) {
	Register rs("s0");
	LsrInstruction lsr(0, &rs, NULL, 0, 0);
	struct ALUFlags flags;
	lsr.setALUFlags(flags);
	rs.put(9);
	ASSERT_EQ(lsr.execute(), 4);
}

TEST(LsrInstruction, NegativeNumber) {
	Register rs("s0");
	LsrInstruction lsr(0, &rs, NULL, 0, 0);
	struct ALUFlags flags;
	lsr.setALUFlags(flags);
	rs.put(-6);
	ASSERT_EQ(lsr.execute(), 32765);
}

TEST(LsrInstruction, NegativeNumberOdd) {
	Register rs("s0");
	LsrInstruction lsr(0, &rs, NULL, 0, 0);
	struct ALUFlags flags;
	lsr.setALUFlags(flags);
	rs.put(-9);
	ASSERT_EQ(lsr.execute(), 32763);
}
