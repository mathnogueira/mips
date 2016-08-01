
#include <gtest/gtest.h>
#include <mips/instructions/format_I/ornotb.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(OrnotbInstruction, differentNumbers) {
	Register rs("s1");
	Register rt("s2");
	OrnotbInstruction ornotb(0, &rs, &rt, 0, 0);
	rs.put(15);
	rt.put(20);
	bit16_t result = ornotb.execute();
	ASSERT_EQ(result, 15);
}

TEST(OrnotbInstruction, equalNumbers) {
	Register rs("s1");
	Register rt("s2");
	OrnotbInstruction ornotb(0, &rs, &rt, 0, 0);
	rs.put(1);
	rt.put(1);
	bit16_t result = ornotb.execute();
	ASSERT_EQ(result, 1);
}

TEST(OrnotbInstruction, OddRs) {
	Register rs("s1");
	Register rt("s2");
	OrnotbInstruction ornotb(0, &rs, &rt, 0, 0);
	rs.put(5);
	rt.put(0);
	bit16_t result = ornotb.execute();
	ASSERT_EQ(result, 5);
}

TEST(OrnotbInstruction, EvenRs) {
	Register rs("s1");
	Register rt("s2");
	OrnotbInstruction ornotb(0, &rs, &rt, 0, 0);
	rs.put(4);
	rt.put(0);
	bit16_t result = ornotb.execute();
	ASSERT_EQ(result, 5);
}