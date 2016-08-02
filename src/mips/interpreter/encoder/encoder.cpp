#include <mips/interpreter/encoder/encoder.hpp>
#include <mips/interpreter/exception/interpreter_exception.hpp>
#include <map>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace MIPS;

static const char* registers[] = {"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7"};

Encoder::Encoder() {}

bit8_t Encoder::getRegisterNumber(const char *name) {
	for (size_t i = 0; i < 8; ++i)
		if (strcmp(name, registers[i]) == 0)
			return i;
	char *err = new char[50];
	sprintf(err, "Register %s does not exist!", name);
	throw InterpreterException(err, 0);
}
