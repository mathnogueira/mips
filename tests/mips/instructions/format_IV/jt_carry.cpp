#include <gtest/gtest.h>
#include <mips/instructions/format_IV/jt_carry.hpp>
#include <mips/flag.hpp>

using namespace MIPS;

TEST(JtCarryInstruction, DesvioNaoTomado) {
    struct ALUFlags flags;
    flags.carry = 0;
    JtCarryInstruction jt_carry(0, flags, 10);
    ASSERT_EQ(jt_carry.execute(), 0);
}

TEST(JtCarryInstruction, DesvioTomado) {
    struct ALUFlags flags;
    flags.carry = 1;
    JtCarryInstruction jt_carry(0, flags, 10);
    ASSERT_EQ(jt_carry.execute(), 1);
}
