#include <gtest/gtest.h>
#include <mips/instructions/format_I/ones.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(OnesInstruction, isOne) {
        Register rd("rc");
	OnesInstruction ones(0, NULL, NULL, &rd, 0, 0);
	rd.put(33);
	bit16_t result = ones.execute();
	ASSERT_EQ(result, 1);
}
