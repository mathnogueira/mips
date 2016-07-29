#include <mips/interpreter/encoder/format_II_encoder.hpp>
#include <cstdlib>

using namespace MIPS;

void FormatIIEncoder::parse(std::vector<char*> &params) {
	this->opcode = 2;
	this->rd = this->getRegisterNumber(params.at(1));
	this->offset = atoi(params.at(2));
}

instruction_t FormatIIEncoder::encode() {
	instruction_t instruction = 0;
	instruction |= (opcode << 14);
	instruction |= (rd << 11);
	instruction |= offset & 0x07ff;
	return instruction;
}
