#include <mips/interpreter/encoder/encoder.hpp>
#include <mips/interpreter/exception/interpreter_exception.hpp>
#include <map>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace MIPS;

static const char* registers[] = {"$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7"};

Encoder::Encoder() {}

bit8_t Encoder::getRegisterNumber(const char *name) {
	for (size_t i = 0; i < 8; ++i)
		if (strcmp(name, registers[i]) == 0)
			return i;
	char err[100];
	sprintf(err, "Register %s does not exist!", name);
	throw InterpreterException(err, 0);
}
