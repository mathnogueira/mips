#include <gtest/gtest.h>
#include <mips/instructions/format_VII/store.hpp>
#include <mips/memory/register.hpp>
#include <mips/memory/memory.hpp>
#include <mips/memory/memory_exception.hpp>
#include <mips/units/control.hpp>

using namespace MIPS;

TEST(StoreTest, storePositive) {
	ControlUnit cu;
    Memory memory(cu);
	cu.memWrite = true;
    memory.setDataSize(3);
    //ASSERT_EQ(memory.read(1), 64);

    Register ra("r3");
    Register rb("r6");
    ra.put(1);
    rb.put(64);

    StoreInstruction store(01, &ra, &rb, &memory);
    store.execute();

    ASSERT_EQ(memory.read(ra.get()), 64);
}
