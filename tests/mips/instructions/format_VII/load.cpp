#include <gtest/gtest.h>
#include <mips/instructions/format_VII/load.hpp>
#include <mips/memory/register.hpp>
#include <mips/memory/memory.hpp>
#include <mips/memory/memory_exception.hpp>
#include <mips/units/control.hpp>

using namespace MIPS;

TEST(LoadTest, LoadPositive) {
	ControlUnit cu;
	cu.memWrite = true;
    Memory memory(cu);
    memory.setDataSize(3);
    memory.write(13, 2); //palavra 13 na posição 2

    Register ra("r3");
    Register rc("r6");

    ra.put(2);

    LoadInstruction load(01, &ra, &rc, &memory);

    ASSERT_EQ(load.execute(), 13);
}
