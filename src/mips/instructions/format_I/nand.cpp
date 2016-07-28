#include <mips/instructions/format_I/nand.hpp>
#include <cstdio>

using namespace MIPS;

void NandInstruction::execute() {
	bit16_t rs = this->rs->get();
	bit16_t rt = this->rt->get();
	bit16_t result = !(rs & rt);
	rd->put(result);
}
