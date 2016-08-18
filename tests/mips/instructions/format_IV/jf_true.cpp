#include <gtest/gtest.h>
#include <mips/instructions/format_IV/jf_true.hpp>
#include <mips/flag.hpp>

using namespace MIPS;

TEST(JfTrueInstruction, DesvioTomado) {
    ALUFlags flags;
    
    JfTrueInstruction jf_true(0, flags, 10);
    ASSERT_EQ(jf_true.execute(), 0);
}

/*TEST(JtTrueInstruction, DesvioNaoTomado) {
    ALUFlags flags;
    
    JtTrueInstruction jt_true(0, flags, 10);
    ASSERT_EQ(jt_true.execute(), 0);
}*/

