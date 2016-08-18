#include <mips/instructions/format_I/zero.hpp>

using namespace MIPS;

bit16_t ZeroInstruction::execute() {
	// this->rd->put(0);

    // Flags
    this->flags->neg = 0;
    this->flags->zero = 1;
    this->flags->carry = 0;
    this->flags->overflow = 0;  
    
	return 0;
}
