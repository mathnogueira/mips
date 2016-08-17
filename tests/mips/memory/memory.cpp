#include <gtest/gtest.h>
#include <mips/memory/memory.hpp>
#include <mips/memory/memory_exception.hpp>
#include <mips/units/control.hpp>

using namespace MIPS;

TEST(Memory, writeAndRetrieveData) {
	ControlUnit cu;
	cu.memRead = true;
	cu.memWrite = true;
    Memory memory(cu);
    memory.setDataSize(8);
    memory.write(256, 4);
    memory.write(512, 2);
    memory.write(722, 7);
    ASSERT_EQ(memory.read(4), 256);
    ASSERT_EQ(memory.read(2), 512);
    ASSERT_EQ(memory.read(7), 722);
}

TEST(Memory, writeAndRetrieveDataFromInvalidOffset) {
	ControlUnit cu;
	cu.memRead = true;
	cu.memWrite = true;
    Memory memory(cu);
    memory.setDataSize(1);
    try {
        memory.write(1024, -1);
    } catch (MemoryException& err) {
        SUCCEED();
    }
}

TEST(Memory, writeAndRetrieveDataFromInvalidOffset2) {
	ControlUnit cu;
	cu.memRead = true;
	cu.memWrite = true;
    Memory memory(cu);
    memory.setDataSize(1);
    try {
        memory.write(1024, 9);
    } catch (MemoryException& err) {
        SUCCEED();
    }
}

TEST(Memory, noWriteFlag) {
	ControlUnit cu;
    Memory memory(cu);
    memory.setDataSize(2);
	cu.memWrite = true;
	memory.write(0, 1);
	cu.memWrite = false;
    memory.write(1024, 1);
	ASSERT_EQ(memory.read(1), 0);
}
