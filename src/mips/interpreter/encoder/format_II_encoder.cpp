#include <mips/interpreter/encoder/format_II_encoder.hpp>
#include <cstdlib>

using namespace MIPS;

void FormatIIEncoder::parse(std::vector<char*> &params) {
    FORMAT_DEBUG("[Codificando instrução %s do formato II]\n", params.at(0));
	this->opcode = 2;
	this->rd = this->getRegisterNumber(params.at(1));
	this->offset = atoi(params.at(2));
}

instruction_t FormatIIEncoder::encode() {
    MESSAGE("Opcode\tRD\tOffset\n");
    FORMAT_DEBUG("%d\t%d\t%d\n\n", opcode, rd, offset);
	instruction_t instruction = 0;
	instruction |= (opcode << 14);
	instruction |= (rd << 11);
	instruction |= offset & 0x07ff;
	return instruction;
}
