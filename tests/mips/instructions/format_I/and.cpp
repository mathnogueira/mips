/////////////////////////////
//Lucas Fonseca dos Santos//
////////////////////////////
#include <gtest/gtest.h>
#include <mips/instructions/format_I/and.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;


TEST(AndInstruction, differentNumbers) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	AndInstruction And(0, &rs, &rt, &rd, 0, 0);
	rs.put(12);
	rt.put(15);
	And.execute();
	ASSERT_EQ(rd.get(), 12);
}

TEST(AndInstruction, equalNumbers) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	AndInstruction And(0, &rs, &rt, &rd, 0, 0);
	rs.put(12);
	rt.put(12);
	And.execute();
	ASSERT_EQ(rd.get(), 12);
}
