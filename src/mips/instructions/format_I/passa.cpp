#include <mips/instructions/format_I/passa.hpp>

using namespace MIPS;

bit16_t PassaInstruction::execute() {
	bit16_t ra = this->rt->get();
	// this->rs->put(ra);
	
    // Flags
    this->flags->neg = ra < 0;
    this->flags->zero = ra == 0;
    this->flags->carry = 0;
    this->flags->overflow = 0;

	return ra;
}
