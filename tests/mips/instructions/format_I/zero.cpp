#include <gtest/gtest.h>
#include <mips/instructions/format_I/zero.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(ZeroInstruction, zero) {
	Register rd("t0");
	ZeroInstruction zero(0, NULL, NULL, 0, 0);
	rd.put(22);
	bit16_t result = zero.execute();
	ASSERT_EQ(result, 0);
}
