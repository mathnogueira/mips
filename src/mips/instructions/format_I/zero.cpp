#include <mips/instructions/format_I/zero.hpp>

using namespace MIPS;

bit16_t ZeroInstruction::execute() {
	// this->rd->put(0);
	// Flags
	this->neg = 0;
	this->zero = 1;
	this->carry = 0;
	this->overflow = 0;
	return 0;
}
