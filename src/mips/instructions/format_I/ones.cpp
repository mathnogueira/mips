#include <mips/instructions/format_I/ones.hpp>

using namespace MIPS;

bit16_t OnesInstruction::execute() {
	this->neg = 0;
	this->zero = 0;
	this->carry = 0;
	this->overflow = 0;
	return 1;
}
