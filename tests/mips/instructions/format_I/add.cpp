#include <gtest/gtest.h>
#include <mips/instructions/format_I/add.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(AddInstruction, sumOk) {
	Register rs("s0");
	Register rt("s1");
	Register rd("s2");
        
	AddInstruction add(0, &rs, &rt, 0, 0);
	rs.put(3);
	rt.put(2);
	rd.put(add.execute());
        
	ASSERT_EQ(rd.get(), 5);
}

TEST(AddInstruction, sumNumNegative) {
	Register rs("s0");
	Register rt("s1");
	Register rd("s2");
        
	AddInstruction add(0, &rs, &rt, 0, 0);
	rs.put(3);
	rt.put(-2);
	rd.put(add.execute());
        
	ASSERT_EQ(rd.get(), 1);
}

TEST(AddInstruction, sumNegativeNegative) {
	Register rs("s0");
	Register rt("s1");
	Register rd("s2");
        
	AddInstruction add(0, &rs, &rt, 0, 0);
	rs.put(-3);
	rt.put(-2);
	rd.put(add.execute());
        
	ASSERT_EQ(rd.get(), -5);
}