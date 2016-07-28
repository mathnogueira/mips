#include <gtest/gtest.h>
#include <mips/instructions/format_I/xnor.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(XnorInstruction, differentNumbers) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	XnorInstruction xnor(0, &rs, &rt, &rd, 0, 0);
	rs.put(12);
	rt.put(15);
	xnor.execute();
	ASSERT_EQ(rd.get(), 0);
}

TEST(XnorInstruction, equalNumbers) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	XnorInstruction xnor(0, &rs, &rt, &rd, 0, 0);
	rs.put(12);
	rt.put(12);
	xnor.execute();
	ASSERT_EQ(rd.get(), 1);
}

TEST(XnorInstruction, positiveNegative) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	XnorInstruction xnor(0, &rs, &rt, &rd, 0, 0);
	rs.put(-12);
	rt.put(15);
	xnor.execute();
	ASSERT_EQ(rd.get(), 0);
}

TEST(XnorInstruction, negativeNumbers) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	XnorInstruction xnor(0, &rs, &rt, &rd, 0, 0);
	rs.put(-12);
	rt.put(-15);
	xnor.execute();
	ASSERT_EQ(rd.get(), 0);
}

TEST(XnorInstruction, sameNegativeNumbers) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	XnorInstruction xnor(0, &rs, &rt, &rd, 0, 0);
	rs.put(-122);
	rt.put(-122);
	xnor.execute();
	ASSERT_EQ(rd.get(), 1);
}
