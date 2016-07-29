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
	OrInstruction Or(0, &rs, &rt, &rd, 0, 0);
	rs.put(12);
	rt.put(15);
	Or.execute();
	ASSERT_EQ(rd.get(), 15);
}

TEST(OrInstruction, equalNumbers) {
	Register rs("s1");
	Register rt("s2");
	Register rd("s0");
	OrInstruction Or(0, &rs, &rt, &rd, 0, 0);
	rs.put(12);
	rt.put(12);
	Or.execute();
	ASSERT_EQ(rd.get(), 12);
}
