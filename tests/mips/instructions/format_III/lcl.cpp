#include <gtest/gtest.h>
#include <mips/instructions/format_III/lcl.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(LclInstruction, positiveNumber) {
	Register rd("t0");
	LclInstruction lcl(0, &rd, 2);
	rd.put(0);
	bit16_t result = lcl.execute();
	ASSERT_EQ(result, 2);
}

TEST(LclInstruction, negativeNumber) {
	Register rd("t0");
	LclInstruction lcl(0, &rd, -1);
	rd.put(0);
	bit16_t result = lcl.execute();
	ASSERT_EQ(result, 255);
}
