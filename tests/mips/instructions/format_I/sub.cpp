#include <gtest/gtest.h>
#include <mips/instructions/format_I/sub.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(SubInstruction, subtrairDoisPositivos) {
    Register rs("s0");
    Register rt("s1");
    SubInstruction subdec(0, &rs, &rt, 0, 0);
    rs.put(20);
    rt.put(10);
    bit16_t result = subdec.execute();
    ASSERT_EQ(result, 10);
}

TEST(SubInstruction, subtrairDoisNegativos) {
    Register rs("s0");
    Register rt("s1");
    SubInstruction subdec(0, &rs, &rt, 0, 0);
    rs.put(-20);
    rt.put(-10);
    bit16_t result = subdec.execute();
    ASSERT_EQ(result, -10);
}

TEST(SubInstruction, subtrairPositivoNegativo) {
    Register rs("s0");
    Register rt("s1");
    SubInstruction subdec(0, &rs, &rt, 0, 0);
    rs.put(20);
    rt.put(-10);
    bit16_t result = subdec.execute();
    ASSERT_EQ(result, 30);
}

TEST(SubInstruction, subtrairNegativoPositivo) {
    Register rs("s0");
    Register rt("s1");
    SubInstruction subdec(0, &rs, &rt, 0, 0);
    rs.put(-40);
    rt.put(10);
    bit16_t result = subdec.execute();
    ASSERT_EQ(result, -50);
}
