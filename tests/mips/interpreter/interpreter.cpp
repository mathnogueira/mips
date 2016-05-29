#include <gtest/gtest.h>
#include <mips/interpreter/interpreter.hpp>

using namespace MIPS;

TEST(Interpreter, constructor) {
	Interpreter i("../tests/input/test1.asm");
	SUCCEED();
}

TEST(Interpreter, process) {
	Interpreter i("../tests/input/test_label.asm");
	i.process();
	SUCCEED();
}
