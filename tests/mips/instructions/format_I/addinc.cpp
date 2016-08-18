#include <gtest/gtest.h>
#include <mips/memory/register.hpp>
#include <mips/instructions/format_I/addinc.hpp>

using namespace MIPS;

TEST(AddIncInstruction, sumOk) {
	Register rs("s0");
	Register rt("s1");
	Register rd("s2");

	AddIncInstruction addinc(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	addinc.setALUFlags(flags);
	rs.put(3);
	rt.put(2);
	rd.put(addinc.execute());

	ASSERT_EQ(rd.get(), 6);
}

TEST(AddIncInstruction, sumNumNegative) {
	Register rs("s0");
	Register rt("s1");
	Register rd("s2");

	AddIncInstruction addinc(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	addinc.setALUFlags(flags);
	rs.put(3);
	rt.put(-2);
	rd.put(addinc.execute());

	ASSERT_EQ(rd.get(), 2);
}

TEST(AddIncInstruction, sumNegativeNegative) {
	Register rs("s0");
	Register rt("s1");
	Register rd("s2");

	AddIncInstruction addinc(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	addinc.setALUFlags(flags);
	rs.put(-3);
	rt.put(-2);
	rd.put(addinc.execute());

	ASSERT_EQ(rd.get(), -4);
}
