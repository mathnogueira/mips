#include <mips/interpreter/encoder/format_III_encoder.hpp>
#include <cstdlib>
#include <cstring>

using namespace MIPS;

void FormatIIIEncoder::parse(std::vector<char*> &params) {
    FORMAT_DEBUG("[Codificando instrução %s do formato III]\n", params.at(0));
	this->opcode = 3;
	this->rd = this->getRegisterNumber(params.at(1));
	this->offset = atoi(params.at(2));
	this->r = (strcmp(params.at(0), "lcl") == 0) ? 0 : 1;
}

instruction_t FormatIIIEncoder::encode() {
    MESSAGE("Opcode\tRD\tR\tOffset\n");
    FORMAT_DEBUG("%d\t%d\t%d\t%d\n\n", opcode, rd, r, offset);
	instruction_t instruction = 0;
	instruction |= (opcode << 14);
	instruction |= (rd << 11);
	instruction |= (r << 10);
	instruction |= (offset & 0x00ff);
	return instruction;
}
