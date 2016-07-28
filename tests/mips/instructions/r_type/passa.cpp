#include <gtest/gtest.h>
#include <mips/instructions/r_type/passa.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(PassaInstruction, copy) {
	Register rc("rc");
	Register ra("ra");
	PassaInstruction passa(0, &rc, NULL, &ra, 0, 0);
	ra.put(20);
	passa.execute();
	ASSERT_EQ(rc.get(), 20);
}
