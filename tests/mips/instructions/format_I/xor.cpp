#include <gtest/gtest.h>
#include <mips/instructions/format_I/xor.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(XorInstruction, zeroZero) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	XorInstruction xOr(0, &rs, &rt, 0, 0);
	rs.put(0);
	rt.put(0);
	bit16_t result = xOr.execute();
	ASSERT_EQ(result, 0);
}

TEST(XorInstruction, zeroOne) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	XorInstruction xOr(0, &rs, &rt, 0, 0);
	rs.put(0);
	rt.put(1);
	bit16_t result = xOr.execute();
	ASSERT_EQ(result, 1);
}

TEST(XorInstruction, oneZero) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	XorInstruction xOr(0, &rs, &rt, 0, 0);
	rs.put(1);
	rt.put(0);
	bit16_t result = xOr.execute();
	ASSERT_EQ(result, 1);
}

TEST(XorInstruction, oneOne) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	XorInstruction xOr(0, &rs, &rt, 0, 0);
	rs.put(1);
	rt.put(1);
	bit16_t result = xOr.execute();
	ASSERT_EQ(result, 0);
}
