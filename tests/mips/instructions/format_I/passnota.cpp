#include <gtest/gtest.h>
#include <mips/instructions/format_I/passnota.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(PassNotAInstruction, complement) {
	Register rc("rc");
	Register ra("ra");
	PassNotAInstruction passnota(0, &rc, &ra, 0, 0);
	ra.put(35);
	bit16_t result = passnota.execute();
	ASSERT_EQ(result, -36);
}

TEST(PassNotAInstruction, complementNegative) {
	Register rc("rc");
	Register ra("ra");
	PassNotAInstruction passnota(0, &rc, &ra, 0, 0);
	ra.put(-9);
	bit16_t result = passnota.execute();
	ASSERT_EQ(result, 8);
}
