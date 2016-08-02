#include <mips/interpreter/encoder/format_VII_encoder.hpp>
#include <cstring>

using namespace MIPS;

void FormatVIIEncoder::parse(std::vector<char*> &params) {
    FORMAT_DEBUG("[Codificando instrução %s do formato VII]\n", params.at(0));
	opcode = 1;
	funct = (strcmp("load", params.at(0)) == 0) ? 20 : 22;
	rd = getRegisterNumber(params.at(1));
	rs = getRegisterNumber(params.at(2));
}

instruction_t FormatVIIEncoder::encode() {
    MESSAGE("Opcode\tRs\tRd\tFunct\n");
    FORMAT_DEBUG("%d\t%d\t%d\t%d\n\n", opcode, rs, rd, funct);
	instruction_t instruction = 0;
	instruction |= (opcode << 14);
	instruction |= (rd << 11);
	instruction |= (funct << 6);
	instruction |= (rs << 3);
	return instruction;
}
