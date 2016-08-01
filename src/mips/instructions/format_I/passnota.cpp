#include <mips/instructions/format_I/passnota.hpp>

using namespace MIPS;

bit16_t PassNotAInstruction::execute() {
	bit16_t ra = this->rt->get();
	// this->rs->put(ra);
	// Flags
	this->neg = 0;
	this->zero = 0;
	this->carry = 0;
	this->overflow = 0;
	return (~ra);
}
