#include <gtest/gtest.h>
#include <mips/instructions/format_IV/jf_zero.hpp>
#include <mips/flag.hpp>

using namespace MIPS;

TEST(JfZeroInstruction, DesvioNaoTomado) {
    struct ALUFlags flags;
    flags.zero = 1;
    JfZeroInstruction jf_zero(0, flags, 10);
    ASSERT_EQ(jf_zero.execute(), 0);
}

TEST(JfZeroInstruction, DesvioTomado) {
    struct ALUFlags flags;
    flags.zero = 0;
    JfZeroInstruction jf_zero(0, flags, 10);
    ASSERT_EQ(jf_zero.execute(), 1);
}
