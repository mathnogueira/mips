////////////////////////////
//Lucas Fonseca dos Santos//
////////////////////////////
//                        //
//      INSTRUÇÃO OR      //
//                        //
////////////////////////////
#include <gtest/gtest.h>
#include <mips/instructions/format_I/or.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;


TEST(OrInstruction, differentNumbers) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	OrInstruction Or(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	Or.setALUFlags(flags);
	rs.put(12);
	rt.put(15);
	bit16_t result = Or.execute();
	ASSERT_EQ(result, 15);
}

TEST(OrInstruction, equalNumbers) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	OrInstruction Or(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	Or.setALUFlags(flags);
	rs.put(12);
	rt.put(12);
	bit16_t result = Or.execute();
	ASSERT_EQ(result, 12);
}
