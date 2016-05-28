#include <mips/interpreter/interpreter.hpp>

using namespace MIPS;

Interpreter::Interpreter(const char* file) {
	this->file = file;
}

bool Interpreter::process() {
	return false;
}
