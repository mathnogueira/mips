#include <mips/interpreter/encoder/format_I_encoder.hpp>

using namespace MIPS;

void FormatIEncoder::parse(std::vector<char*> &params) {
	this->opcode = 1;
	this->rd = this->getRegisterNumber(params.at(1));
	this->rs = this->getRegisterNumber(params.at(2));
	this->rt = this->getRegisterNumber(params.at(3));
}

instruction_t FormatIEncoder::encode() {
	return 0;
}
