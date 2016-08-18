#include <gtest/gtest.h>
#include <mips/instructions/format_IV/jt_negzero.hpp>
#include <mips/flag.hpp>

using namespace MIPS;

TEST(JtNegzeroInstruction, DesvioNaoTomadoZero) {
    struct ALUFlags flags;
    flags.zero = 0;
    flags.neg = 0;
    JtNegzeroInstruction jt_negzero(0, flags, 10);
    ASSERT_EQ(jt_negzero.execute(), 0);
}

TEST(JtNegzeroInstruction, DesvioNaoTomadoNeg) {
    struct ALUFlags flags;
    flags.zero = 0;
    flags.neg = 0;
    JtNegzeroInstruction jt_negzero(0, flags, 10);
    ASSERT_EQ(jt_negzero.execute(), 0);
}

TEST(JtNegzeroInstruction, DesvioTomadoNeg) {
    struct ALUFlags flags;
    flags.neg = 1;
    JtNegzeroInstruction jt_negzero(0, flags, 10);
    ASSERT_EQ(jt_negzero.execute(), 1);
}

TEST(JtNegzeroInstruction, DesvioTomadoZero) {
    struct ALUFlags flags;
    flags.zero = 1;
    JtNegzeroInstruction jt_negzero(0, flags, 10);
    ASSERT_EQ(jt_negzero.execute(), 1);
}