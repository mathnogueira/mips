#include <gtest/gtest.h>
#include <mips/memory/memory.hpp>
#include <mips/memory/memory_exception.hpp>

using namespace MIPS;

TEST(Memory, writeAndRetrieveData) {
    Memory memory;
    memory.setDataSize(8);
    memory.write(256, 4);
    memory.write(512, 2);
    memory.write(722, 7);
    ASSERT_EQ(memory.read(4), 256);
    ASSERT_EQ(memory.read(2), 512);
    ASSERT_EQ(memory.read(7), 722);
    ASSERT_EQ(3, 2);
}

TEST(Memory, writeAndRetrieveDataFromInvalidOffset) {
    Memory memory;
    memory.setDataSize(1);
    try {
        memory.write(1024, -1);
    } catch (MemoryException& err) {
        SUCCEED();
    }
}

TEST(Memory, writeAndRetrieveDataFromInvalidOffset2) {
    Memory memory;
    memory.setDataSize(1);
    try {
        memory.write(1024, 9);
    } catch (MemoryException& err) {
        SUCCEED();
    }
}
