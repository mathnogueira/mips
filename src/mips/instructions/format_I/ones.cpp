#include <mips/instructions/format_I/ones.hpp>

using namespace MIPS;

bit16_t OnesInstruction::execute() {
	this->flags->neg = 0;
    this->flags->zero = 0;
    this->flags->carry = 0;
    this->flags->overflow = 0;
    
	return 1;
}
