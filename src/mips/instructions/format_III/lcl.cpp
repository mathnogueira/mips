#include <mips/instructions/format_III/lcl.hpp>
#include <mips/circuits/signal_extender.hpp>
#include <cstdio>

using namespace MIPS;

bit16_t LclInstruction::execute() {
	bit16_t rd = this->rd->get();
	bit16_t result = ((this->offset & 0x00ff) | (rd & 0xff00));
	// this->rd->put(result);
	// Não afeta nenhuma flag
	return result;
}
