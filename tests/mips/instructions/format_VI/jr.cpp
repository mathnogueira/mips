#include <gtest/gtest.h>
#include <mips/instructions/format_VI/jr.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(JrTest, JumpRegister) {

    Register rs("r7");
    Register rt("rt");
    Register pc("PC");
    rt.put(6);

    JrInstruction jr(11, &rs, &rt, &pc);
    jr.execute();

    ASSERT_EQ(pc.get(), 6);
}
