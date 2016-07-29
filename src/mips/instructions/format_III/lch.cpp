#include <mips/instructions/format_III/lch.hpp>

using namespace MIPS;

void LchInstruction::execute() {
	bit16_t rd = this->rd->get();
	bit16_t result = ((this->offset << 8) | (rd & 0x00ff));
	this->rd->put(result);
	// Não afeta nenhuma flag
}
