#include <gtest/gtest.h>
#include <mips/instructions/format_IV/jt_overflow.hpp>
#include <mips/flag.hpp>

using namespace MIPS;

TEST(JtOverflowInstruction, DesvioNaoTomado) {
    struct ALUFlags flags;
    flags.overflow = 0;
    JtOverflowInstruction jt_overflow(0, flags, 10);
    ASSERT_EQ(jt_overflow.execute(), 0);
}

TEST(JtOverflowInstruction, DesvioTomado) {
    struct ALUFlags flags;
    flags.overflow = 1;
    JtOverflowInstruction jt_overflow(0, flags, 10);
    ASSERT_EQ(jt_overflow.execute(), 1);
}
