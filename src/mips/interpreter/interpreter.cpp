#include <mips/interpreter/interpreter.hpp>
#include <mips/util/filter/space_filter.hpp>

using namespace MIPS;

Interpreter::Interpreter(const char* file) {
	SpaceFilter spaceFilter;
	fileReader = new FileReader(file, spaceFilter);
}

Interpreter::~Interpreter() {
	delete fileReader;
}

bool Interpreter::process() {
	return false;
}
