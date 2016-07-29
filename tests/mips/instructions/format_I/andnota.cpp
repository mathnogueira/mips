#include <gtest/gtest.h>
#include <mips/instructions/format_I/andnota.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(AndnotaInstruction, differentNumbers) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	AndnotaInstruction andnota(0, &rs, &rt, &rd, 0, 0);
	rs.put(12);
	rt.put(15);
	andnota.execute();
	ASSERT_EQ(rd.get(), 0);
}

TEST(AndnotaInstruction, equalNumbers) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	AndnotaInstruction andnota(0, &rs, &rt, &rd, 0, 0);
	rs.put(12);
	rt.put(12);
	andnota.execute();
	ASSERT_EQ(rd.get(), 0);
}
