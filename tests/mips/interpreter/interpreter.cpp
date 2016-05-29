#include <gtest/gtest.h>
#include <mips/interpreter/interpreter.hpp>

using namespace MIPS;

TEST(Interpreter, constructor) {
	Interpreter i("../tests/input/test.asm");
	SUCCEED();
}
