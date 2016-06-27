#include <mips/interpreter/exception/interpreter_exception.hpp>
#include <mips/interpreter/interpreter.hpp>
#include <gtest/gtest.h>

using namespace MIPS;

TEST(Interpreter, constructor) {
	Interpreter i("../tests/input/test1.asm");
	SUCCEED();
}

TEST(Interpreter, process) {
	Interpreter i("../tests/input/test_label.asm");
	i.processInput();
	SUCCEED();
}

TEST(Interpreter, input_errors) {
	Interpreter i("../tests/input/teste_invalid.asm");
	i.processInput();
	SUCCEED();
}
