#include <mips/instructions/format_III/lcl.hpp>
#include <mips/circuits/signal_extender.hpp>
#include <cstdio>

using namespace MIPS;

void LclInstruction::execute() {
	bit16_t rd = this->rd->get();
	bit16_t result = ((this->offset & 0x00ff) | (rd & 0xff00));
	printf("Offset: %d\n", offset);
	this->rd->put(result);
}
