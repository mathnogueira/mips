#include <gtest/gtest.h>
#include <mips/instructions/format_I/ones.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(OnesInstruction, isOne) {
        Register rd("rc");
	OnesInstruction ones(0, NULL, NULL, 0, 0);
	struct ALUFlags flags;
	ones.setALUFlags(flags);
	rd.put(33);
	bit16_t result = ones.execute();
	ASSERT_EQ(result, 1);
}
