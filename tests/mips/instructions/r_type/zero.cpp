#include <gtest/gtest.h>
#include <mips/instructions/r_type/zero.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(ZeroInstruction, zero) {
	Register rd("t0");
	ZeroInstruction zero(0, NULL, NULL, &rd, 0, 0);
	rd.put(22);
	zero.execute();
	ASSERT_EQ(rd.get(), 0);
}
