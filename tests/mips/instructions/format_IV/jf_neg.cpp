#include <gtest/gtest.h>
#include <mips/instructions/format_IV/jf_neg.hpp>
#include <mips/flag.hpp>

using namespace MIPS;

TEST(JfNegInstruction, DesvioNaoTomado) {
    struct ALUFlags flags;
    flags.neg = 1;
    JfNegInstruction jf_neg(0, flags, 10);
    ASSERT_EQ(jf_neg.execute(), 0);
}

TEST(JfNegInstruction, DesvioTomado) {
    struct ALUFlags flags;
    flags.neg = 0;
    JfNegInstruction jf_neg(0, flags, 10);
    ASSERT_EQ(jf_neg.execute(), 1);
}
