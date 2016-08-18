#include <gtest/gtest.h>
#include <mips/instructions/format_IV/jf_overflow.hpp>
#include <mips/flag.hpp>

using namespace MIPS;

TEST(JfOverflowInstruction, DesvioNaoTomado) {
    struct ALUFlags flags;
    flags.overflow = 1;
    JfOverflowInstruction jf_overflow(0, flags, 10);
    ASSERT_EQ(jf_overflow.execute(), 0);
}

TEST(JfOverflowInstruction, DesvioTomado) {
    struct ALUFlags flags;
    flags.overflow = 0;
    JfOverflowInstruction jf_overflow(0, flags, 10);
    ASSERT_EQ(jf_overflow.execute(), 1);
}
