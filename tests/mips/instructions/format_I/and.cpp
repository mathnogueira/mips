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
	AndInstruction And(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	And.setALUFlags(flags);
	rs.put(12);
	rt.put(15);
	bit16_t result = And.execute();
	ASSERT_EQ(result, 12);
}

TEST(AndInstruction, equalNumbers) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	AndInstruction And(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	And.setALUFlags(flags);
	rs.put(12);
	rt.put(12);
	bit16_t result = And.execute();
	ASSERT_EQ(result, 12);
}
