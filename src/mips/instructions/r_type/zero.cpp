#include <mips/instructions/r_type/zero.hpp>

using namespace MIPS;

void ZeroInstruction::execute() {
	this->rd->put(0);
	this->neg = 0;
	this->zero = 1;
	this->carry = 0;
	this->overflow = 0;
}
