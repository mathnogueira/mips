#include <gtest/gtest.h>
#include <mips/instructions/format_I/nand.hpp>

using namespace MIPS;

TEST(NandInstruction, differentNumbers) {
	Register rs("s0");
	Register rt("s1");
	Register rd("s2");
	NandInstruction nand(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	nand.setALUFlags(flags);
	rs.put(2);
	rt.put(0);
	bit16_t result = nand.execute();
	ASSERT_EQ(result, 1);
}

TEST(NandInstruction, EqualNumbers) {
	Register rs("s0");
	Register rt("s1");
	Register rd("s2");
	NandInstruction nand(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	nand.setALUFlags(flags);
	rs.put(2);
	rt.put(2);
	bit16_t result = nand.execute();
	ASSERT_EQ(result, 0);
}
