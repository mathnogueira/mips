#include <gtest/gtest.h>
#include <mips/instructions/format_I/nor.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(NorInstruction, zeroZero) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	NorInstruction nor(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	nor.setALUFlags(flags);
	rs.put(0);
	rt.put(0);
	bit16_t result = nor.execute();
	ASSERT_EQ(result, 1);
}

TEST(NorInstruction, zeroOne) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	NorInstruction nor(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	nor.setALUFlags(flags);
	rs.put(0);
	rt.put(1);
	bit16_t result = nor.execute();
	ASSERT_EQ(result, 0);
}

TEST(NorInstruction, oneZero) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	NorInstruction nor(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	nor.setALUFlags(flags);
	rs.put(1);
	rt.put(0);
	bit16_t result = nor.execute();
	ASSERT_EQ(result, 0);
}

TEST(NorInstruction, oneOne) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	NorInstruction nor(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	nor.setALUFlags(flags);
	rs.put(1);
	rt.put(1);
	bit16_t result = nor.execute();
	ASSERT_EQ(result, 0);
}
