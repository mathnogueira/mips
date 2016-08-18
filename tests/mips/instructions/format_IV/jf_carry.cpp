#include <gtest/gtest.h>
#include <mips/instructions/format_IV/jf_carry.hpp>
#include <mips/flag.hpp>

using namespace MIPS;

TEST(JfCarryInstruction, DesvioNaoTomado) {
    struct ALUFlags flags;
    flags.carry = 0;
    JfCarryInstruction jf_carry(0, flags, 10);
    ASSERT_EQ(jf_carry.execute(), 1);
}

TEST(JfCarryInstruction, DesvioTomado) {
    struct ALUFlags flags;
    flags.carry = 1;
    JfCarryInstruction jf_carry(0, flags, 10);
    ASSERT_EQ(jf_carry.execute(), 0);
}
