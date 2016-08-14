#include <gtest/gtest.h>
#include <mips/instructions/format_VII/load.hpp>
#include <mips/memory/register.hpp>
#include <mips/memory/memory.hpp>
#include <mips/memory/memory_exception.hpp>

using namespace MIPS;

TEST(LoadTest, LoadPositive) {
    Memory memory;
    memory.setDataSize(3);
    memory.write(13, 2); //palavra 13 na posição 2

    Register ra("r3");
    Register rc("r6");
    
    ra.put(2);

    LoadInstruction load(01, &ra, &rc, &memory);
    load.execute();
   
    ASSERT_EQ(rc.get(), 13);
}