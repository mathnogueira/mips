#include <mips/interpreter/encoder/format_III_encoder.hpp>
#include <cstdlib>
#include <cstring>

using namespace MIPS;

void FormatIIIEncoder::parse(std::vector<char*> &params) {
	this->opcode = 3;
	this->rd = this->getRegisterNumber(params.at(1));
	this->offset = atoi(params.at(2));
	this->r = (strcmp(params.at(0), "lcl") == 0) ? 0 : 1;
	printf("%d\n", r);
}

instruction_t FormatIIIEncoder::encode() {
	instruction_t instruction = 0;
	PRINT_BIN(instruction);
	instruction |= (opcode << 14);
	PRINT_BIN(instruction);
	instruction |= (rd << 11);
	PRINT_BIN(instruction);
	instruction |= (r << 10);
	PRINT_BIN(instruction);
	instruction |= (offset & 0x00ff);
	PRINT_BIN(instruction);
	return instruction;
}
