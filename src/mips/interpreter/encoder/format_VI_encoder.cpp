#include <mips/interpreter/encoder/format_VI_encoder.hpp>
#include <cstring>

using namespace MIPS;

void FormatVIEncoder::parse(std::vector<char*> &params) {
    FORMAT_DEBUG("[Codificando instrução %s do formato VI]\n", params.at(0));
	opcode = 0;
	funct = 3;
	r = (strcmp("jal", params.at(0)) == 0) ? 0 : 1;
	rt = getRegisterNumber(params.at(1));
}

instruction_t FormatVIEncoder::encode() {
    MESSAGE("Opcode\tFunct\tR\tRt\n");
    FORMAT_DEBUG("%d\t%d\t%d\t%d\n\n", opcode, funct, r, rt);
	instruction_t instruction = 0;
	instruction |= (opcode << 14);
	instruction |= (funct << 12);
	instruction |= (r << 11);
	instruction |= (rt & 0x0007);
	return instruction;
}
