#include <mips/instructions/format_I/ones.hpp>

using namespace MIPS;

void OnesInstruction::execute() {
	this->rd->put(1);
	this->neg = 0;
	this->zero = 0;
	this->carry = 0;
	this->overflow = 0;
}
