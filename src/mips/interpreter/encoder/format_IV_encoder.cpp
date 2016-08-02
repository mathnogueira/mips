#include <mips/interpreter/encoder/format_IV_encoder.hpp>
#include <cstring>
#include <cstdlib>

using namespace MIPS;

void FormatIVEncoder::parse(std::vector<char*> &params) {
	char *name = params.at(0);
	if (strcmp("jt.neg", name) == 0) {
		this->cond = 4;
		this->opcode = 0;
		this->funct = 1;
	} else if (strcmp("jt.zero", name) == 0) {
		this->cond = 5;
		this->opcode = 0;
		this->funct = 1;
	} else if (strcmp("jt.carry", name) == 0) {
		this->cond = 6;
		this->opcode = 0;
		this->funct = 1;
	} else if (strcmp("jt.negzero", name) == 0) {
		this->cond = 7;
		this->opcode = 0;
		this->funct = 1;
	} else if (strcmp("jt.true", name) == 0) {
		this->cond = 0;
		this->opcode = 0;
		this->funct = 1;
	} else if (strcmp("jt.overflow", name) == 0) {
		this->cond = 3;
		this->opcode = 0;
		this->funct = 1;
	} else if (strcmp("jf.neg", name) == 0) {
		this->cond = 4;
		this->opcode = 0;
		this->funct = 0;
	} else if (strcmp("jf.zero", name) == 0) {
		this->cond = 5;
		this->opcode = 0;
		this->funct = 0;
	} else if (strcmp("jf.carry", name) == 0) {
		this->cond = 6;
		this->opcode = 0;
		this->funct = 0;
	} else if (strcmp("jf.negzero", name) == 0) {
		this->cond = 7;
		this->opcode = 0;
		this->funct = 0;
	} else if (strcmp("jf.true", name) == 0) {
		this->cond = 0;
		this->opcode = 0;
		this->funct = 0;
	} else if (strcmp("jf.overflow", name) == 0) {
		this->cond = 3;
		this->opcode = 0;
		this->funct = 0;
	}
	this->offset = atoi(params.at(1));
}

instruction_t FormatIVEncoder::encode() {
	instruction_t instruction = 0;
	instruction |= (opcode << 14);
	instruction |= (funct << 12);
	instruction |= (cond << 8) & 0x0f00;
	instruction |= (offset & 0x00ff);
	return instruction;
}
