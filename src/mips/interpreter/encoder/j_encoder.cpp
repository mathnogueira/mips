#include <mips/interpreter/encoder/j_encoder.hpp>

using namespace MIPS;

instruction32_t JEncoder::encode() {
	instruction32_t instruction = opcode;
	instruction = instruction << 26;
	instruction += address;
	return instruction;
}
