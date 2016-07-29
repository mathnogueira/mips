#include <gtest/gtest.h>
#include <mips/instructions/format_III/lch.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(LchInstruction, positiveNumber) {
	Register rd("t0");
	LchInstruction lch(0, &rd, 2);
	rd.put(1);
	lch.execute();
	ASSERT_EQ(rd.get(), 513);
}

TEST(LchInstruction, negativeNumber) {
	Register rd("t0");
	LchInstruction lch(0, &rd, -1);
	rd.put(0);
	lch.execute();
	ASSERT_EQ(rd.get(), -256);
}
