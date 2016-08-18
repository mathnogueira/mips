#include <gtest/gtest.h>
#include <mips/instructions/format_IV/jt_neg.hpp>
#include <mips/flag.hpp>

using namespace MIPS;

TEST(JtNegInstruction, DesvioNaoTomado) {
    struct ALUFlags flags;
    flags.neg = 3;
    JtNegInstruction jt_neg(0, flags, 10);
    ASSERT_EQ(jt_neg.execute(), 0);
}

TEST(JtNegInstruction, DesvioTomado) {
    struct ALUFlags flags;
    flags.neg = -3;
    JtNegInstruction jt_neg(0, flags, 10);
    ASSERT_EQ(jt_neg.execute(), 1);
}
