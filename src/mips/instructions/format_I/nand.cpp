#include <mips/instructions/format_I/nand.hpp>
#include <cstdio>

using namespace MIPS;

bit16_t NandInstruction::execute() {
	bit16_t rs = this->rs->get();
	bit16_t rt = this->rt->get();
	bit16_t result = !(rs & rt);
	// rd->put(result);
	
    // Flags
    this->flags->neg = result < 0;
    this->flags->zero = result == 0;
    this->flags->carry = 0;
    this->flags->overflow = 0;

	return result;
}
