#include <gtest/gtest.h>
#include <mips/instructions/r_type/nand.hpp>

using namespace MIPS;

TEST(NandInstruction, differentNumbers) {
	Register rs("s0");
	Register rt("s1");
	Register rd("s2");
	NandInstruction nand(0, &rs, &rt, &rd, 0, 0);
	rs.put(2);
	rt.put(0);
	nand.execute();
	ASSERT_EQ(rd.get(), 1);
}

TEST(NandInstruction, EqualNumbers) {
	Register rs("s0");
	Register rt("s1");
	Register rd("s2");
	NandInstruction nand(0, &rs, &rt, &rd, 0, 0);
	rs.put(2);
	rt.put(2);
	nand.execute();
	ASSERT_EQ(rd.get(), 0);
}
