#include <gtest/gtest.h>
#include <mips/instructions/format_IV/jf_negzero.hpp>
#include <mips/flag.hpp>

using namespace MIPS;

TEST(JfNegzeroInstruction, DesvioNaoTomado) {
    struct ALUFlags flags;
    flags.zero = 1;
    flags.neg = 1;
    JfNegzeroInstruction jf_negzero(0, flags, 10);
    ASSERT_EQ(jf_negzero.execute(), 0);
}

TEST(JfNegzeroInstruction, DesvioNaoTomadoNeg) {
    struct ALUFlags flags;
    flags.zero = 1;
    flags.neg = 0;
    JfNegzeroInstruction jf_negzero(0, flags, 10);
    ASSERT_EQ(jf_negzero.execute(), 0);
}

TEST(JfNegzeroInstruction, DesvioNaoTomadoZero) {
    struct ALUFlags flags;
    flags.zero = 0;
    flags.neg = 1;
    JfNegzeroInstruction jf_negzero(0, flags, 10);
    ASSERT_EQ(jf_negzero.execute(), 0);
}

TEST(JfNegzeroInstruction, DesvioTomadoZeroNeg) {
    struct ALUFlags flags;
    flags.zero = 0;
    flags.neg = 0;
    JfNegzeroInstruction jf_negzero(0, flags, 10);
    ASSERT_EQ(jf_negzero.execute(), 1);
}