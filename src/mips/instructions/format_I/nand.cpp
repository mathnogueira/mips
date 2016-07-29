#include <mips/instructions/format_I/nand.hpp>
#include <cstdio>

using namespace MIPS;

bit16_t NandInstruction::execute() {
	bit16_t rs = this->rs->get();
	bit16_t rt = this->rt->get();
	bit16_t result = !(rs & rt);
	// rd->put(result);
	// Flags
	this->neg = 0;
	this->zero = 0;
	this->carry = 0;
	this->overflow = 0;
	return result;
}
