#include <gtest/gtest.h>
#include <mips/instructions/format_I/andnota.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(AndnotaInstruction, differentNumbers) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	AndnotaInstruction andnota(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	andnota.setALUFlags(flags);
	rs.put(12);
	rt.put(15);
	bit16_t result = andnota.execute();
	ASSERT_EQ(result, 0);
}

TEST(AndnotaInstruction, equalNumbers) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	AndnotaInstruction andnota(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	andnota.setALUFlags(flags);
	rs.put(12);
	rt.put(12);
	bit16_t result = andnota.execute();
	ASSERT_EQ(result, 0);
}
