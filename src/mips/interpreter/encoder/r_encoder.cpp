#include <mips/interpreter/encoder/r_encoder.hpp>

using namespace MIPS;

instruction32_t REncoder::encode(std::vector<char*>& params) {
	bit8_t opcode, r1, r2, r3, funct;
	struct InstructionInfo info;
	instruction32_t instruction;
	info = getInstructionInfo(params.at(0));
	opcode = info.opcode;
	funct = info.funct;
	r1 = getRegisterNumber(params.at(1));
	r2 = getRegisterNumber(params.at(2));
	r3 = getRegisterNumber(params.at(3));
	// Forma a instrução 32 bits
	instruction += opcode;
	instruction <<= 6;
	instruction += r1;
	instruction <= 5;
	instruction += r2;
	instruction <= 5;
	instruction += r3;
	instruction <= 5;
}
