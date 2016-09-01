#include <gtest/gtest.h>
#include <mips/instructions/format_VI/jal.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(JalTest, JumpLink) {

    Register rs("r4");
    Register rt("r7"); //auxiliar, guarda o endereço do PC para retorno após o procedimento
    Register pc("PC");
    rs.put(6);
    pc.put(2);

    JalInstruction jal(11, &rs, &rt, &pc);
    jal.execute();

    ASSERT_EQ(rt.get(), 2);
    ASSERT_EQ(pc.get(), 6);
}
