#include <mips/interpreter/encoder/format_VI_encoder.hpp>
#include <cstring>

using namespace MIPS;

void FormatVIEncoder::parse(std::vector<char*> &params) {
	opcode = 0;
	funct = 3;
	r = (strcmp("jal", params.at(0)) == 0) ? 0 : 1;
	rt = getRegisterNumber(params.at(1));
}

instruction_t FormatVIEncoder::encode() {
	instruction_t instruction = 0;
	PRINT_BIN(instruction);
	instruction |= (opcode << 14);
	PRINT_BIN(instruction);
	instruction |= (funct << 12);
	PRINT_BIN(instruction);
	instruction |= (r << 11);
	PRINT_BIN(instruction);
	instruction |= (rt & 0x0007);
	PRINT_BIN(instruction);
	return instruction;
}
