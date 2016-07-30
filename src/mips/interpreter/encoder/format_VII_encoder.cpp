#include <mips/interpreter/encoder/format_VII_encoder.hpp>
#include <cstring>

using namespace MIPS;

void FormatVIIEncoder::parse(std::vector<char*> &params) {
	opcode = 1;
	funct = (strcmp("load", params.at(0)) == 0) ? 20 : 22;
	rd = getRegisterNumber(params.at(1));
	rs = getRegisterNumber(params.at(2));
}

instruction_t FormatVIIEncoder::encode() {
	instruction_t instruction = 0;
	PRINT_BIN(instruction);
	instruction |= (opcode << 14);
	PRINT_BIN(instruction);
	instruction |= (rd << 11);
	PRINT_BIN(instruction);
	instruction |= (funct << 6);
	PRINT_BIN(instruction);
	instruction |= (rs << 3);
	PRINT_BIN(instruction);
	return instruction;
}
