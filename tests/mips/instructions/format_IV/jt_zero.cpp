#include <gtest/gtest.h>
#include <mips/instructions/format_IV/jt_zero.hpp>
#include <mips/flag.hpp>

using namespace MIPS;

TEST(JtZeroInstruction, DesvioNaoTomado) {
    struct ALUFlags flags;
    flags.zero = 0;
    JtZeroInstruction jt_zero(0, flags, 10);
    ASSERT_EQ(jt_zero.execute(), 0);
}

TEST(JtZeroInstruction, DesvioTomado) {
    struct ALUFlags flags;
    flags.zero = 1;
    JtZeroInstruction jt_zero(0, flags, 10);
    ASSERT_EQ(jt_zero.execute(), 1);
}
