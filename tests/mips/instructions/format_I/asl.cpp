#include <gtest/gtest.h>
#include <mips/instructions/format_I/asl.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(AslInstruction, positiveNumber) {
	Register rs("s0");
	AslInstruction asl(0, &rs, NULL, 0, 0);
	rs.put(6);
	ASSERT_EQ(asl.execute(), 12);
}

TEST(AslInstruction, positiveNumberOdd) {
	Register rs("s0");
	AslInstruction asl(0, &rs, NULL, 0, 0);
	rs.put(9);
	ASSERT_EQ(asl.execute(), 18);
}

TEST(AslInstruction, NegativeNumber) {
	Register rs("s0");
	AslInstruction asl(0, &rs, NULL, 0, 0);
	rs.put(-6);
	ASSERT_EQ(asl.execute(), -12);
}

TEST(AslInstruction, NegativeNumberOdd) {
	Register rs("s0");
	AslInstruction asl(0, &rs, NULL, 0, 0);
	rs.put(-9);
	ASSERT_EQ(asl.execute(), -18);
}
