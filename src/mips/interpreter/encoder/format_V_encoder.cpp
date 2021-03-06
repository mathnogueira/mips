#include <mips/interpreter/encoder/format_V_encoder.hpp>
#include <cstdlib>

using namespace MIPS;

void FormatVEncoder::parse(std::vector<char*> &params) {
    FORMAT_DEBUG("[Codificando instrução %s do formato V]\n", params.at(0));
	this->opcode = 0;
	this->offset = atoi(params.at(1));
}

instruction_t FormatVEncoder::encode() {
    MESSAGE("Opcode\tOffset\n");
    FORMAT_DEBUG("%d\t%d\n\n", opcode, offset);
	instruction_t instruction = 0;
	if (offset >= 0) {
		instruction |= (opcode << 14);
	    instruction |= (2 << 12);
		instruction |= (offset & 0x0fff);
	} else {
		instruction = 0x2fff;
	}
	return instruction;
}
