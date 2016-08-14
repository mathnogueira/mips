#include <gtest/gtest.h>
#include <mips/instructions/format_I/rsl.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(RslInstruction, positiveNumber) {
	Register rs("s0");
	RslInstruction rsl(0, &rs, NULL, 0, 0);
	rs.put(6);
	ASSERT_EQ(rsl.execute(), 3);
}

TEST(RslInstruction, positiveNumberOdd) {
	Register rs("s0");
	RslInstruction rsl(0, &rs, NULL, 0, 0);
	rs.put(9);
	ASSERT_EQ(rsl.execute(), 4);
}

TEST(RslInstruction, NegativeNumber) {
	Register rs("s0");
	RslInstruction rsl(0, &rs, NULL, 0, 0);
	rs.put(-6);
	ASSERT_EQ(rsl.execute(), -3);
}

TEST(RslInstruction, NegativeNumberOdd) {
	Register rs("s0");
	RslInstruction rsl(0, &rs, NULL, 0, 0);
	rs.put(-9);
	ASSERT_EQ(rsl.execute(), -5);
}