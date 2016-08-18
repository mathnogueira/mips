#include <gtest/gtest.h>
#include <mips/instructions/format_I/subdec.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(SubDecInstruction, subtrairDoisPositivos) {
    Register rs("s0");
    Register rt("s1");
    SubdecInstruction subdec(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	subdec.setALUFlags(flags);
    rs.put(20);
    rt.put(10);
    bit16_t result = subdec.execute();
    ASSERT_EQ(result, 9);
}

TEST(SubDecInstruction, subtrairDoisNegativos) {
    Register rs("s0");
    Register rt("s1");
    SubdecInstruction subdec(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	subdec.setALUFlags(flags);
    rs.put(-20);
    rt.put(-10);
    bit16_t result = subdec.execute();
    ASSERT_EQ(result, -11);
}

TEST(SubDecInstruction, subtrairPositivoNegativo) {
    Register rs("s0");
    Register rt("s1");
    SubdecInstruction subdec(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	subdec.setALUFlags(flags);
    rs.put(20);
    rt.put(-10);
    bit16_t result = subdec.execute();
    ASSERT_EQ(result, 29);
}

TEST(SubDecInstruction, subtrairNegativoPositivo) {
    Register rs("s0");
    Register rt("s1");
    SubdecInstruction subdec(0, &rs, &rt, 0, 0);
	struct ALUFlags flags;
	subdec.setALUFlags(flags);
    rs.put(-40);
    rt.put(10);
    bit16_t result = subdec.execute();
    ASSERT_EQ(result, -51);
}
