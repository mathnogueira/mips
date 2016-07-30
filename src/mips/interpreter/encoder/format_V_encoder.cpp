#include <mips/interpreter/encoder/format_V_encoder.hpp>
#include <cstdlib>

using namespace MIPS;

void FormatVEncoder::parse(std::vector<char*> &params) {
	this->opcode = 2;
	this->offset = atoi(params.at(1));
}

instruction_t FormatVEncoder::encode() {
	instruction_t instruction = 0;
	PRINT_BIN(instruction);
	instruction |= (opcode << 14);
	PRINT_BIN(instruction);
	instruction |= (offset & 0x0fff);
	PRINT_BIN(instruction);
	return instruction;
}
