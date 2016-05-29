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
	i.process();
	SUCCEED();
}

TEST(Interpreter, invalidInstruction) {
	Interpreter i("../tests/input/teste_invalid.asm");
	try {
		i.process();
	} catch (InterpreterException& e) {
		ASSERT_STREQ("subi", e.what());
	}
	ASSERT_TRUE(i.ok() == false);
	SUCCEED();
}
