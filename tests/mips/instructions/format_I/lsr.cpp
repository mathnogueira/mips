#include <gtest/gtest.h>
#include <mips/instructions/format_I/lsr.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(LsrInstruction, positiveNumber) {
	Register rs("s0");
	LsrInstruction lsr(0, &rs, NULL, 0, 0);
	rs.put(2);
	ASSERT_EQ(lsr.execute(), 1);
}

TEST(LsrInstruction, positiveNumberOdd) {
	Register rs("s0");
	LsrInstruction lsr(0, &rs, NULL, 0, 0);
	rs.put(9);
	ASSERT_EQ(lsr.execute(), 4);
}

TEST(LsrInstruction, NegativeNumber) {
	Register rs("s0");
	LsrInstruction lsr(0, &rs, NULL, 0, 0);
	rs.put(-6);
	ASSERT_EQ(lsr.execute(), -3);
}

TEST(LsrInstruction, NegativeNumberOdd) {
	Register rs("s0");
	LsrInstruction lsr(0, &rs, NULL, 0, 0);
	rs.put(-9);
	ASSERT_EQ(lsr.execute(), -5);
}