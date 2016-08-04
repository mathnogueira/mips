#include <mips/instructions/format_III/lch.hpp>

using namespace MIPS;

bit16_t LchInstruction::execute() {
	bit16_t rd = this->rd->get();
    bit16_t offset = this->offset;
	bit16_t result = ((offset << 8) | (rd & 0x00ff));
	// this->rd->put(result);
	// Não afeta nenhuma flag
	return result;
}
