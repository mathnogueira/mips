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
	instruction |= (opcode << 14);
	instruction |= (rd << 11);
	instruction |= (funct << 6);
	instruction |= (rs << 3);
	return instruction;
}
