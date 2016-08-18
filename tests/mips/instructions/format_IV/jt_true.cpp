#include <gtest/gtest.h>
#include <mips/instructions/format_IV/jt_true.hpp>
#include <mips/flag.hpp>

using namespace MIPS;

TEST(JtTrueInstruction, DesvioTomado) {
    ALUFlags flags;
    
    JtTrueInstruction jt_true(0, flags, 10);
    ASSERT_EQ(jt_true.execute(), 1);
}

/*TEST(JtTrueInstruction, DesvioNaoTomado) {
    ALUFlags flags;
    
    JtTrueInstruction jt_true(0, flags, 10);
    ASSERT_EQ(jt_true.execute(), 0);
}*/

