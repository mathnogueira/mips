#include <mips/interpreter/encoder/j_encoder.hpp>

using namespace MIPS;

instruction_t JEncoder::encode() {
	instruction_t instruction = opcode;
	instruction = instruction << 26;
	instruction += address;
	return instruction;
}
