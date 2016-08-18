#include <mips/instructions/format_I/lsl.hpp>
#include <mips/circuits/full_adder.hpp>

using namespace MIPS;

bit16_t LslInstruction::execute() {
	bit16_t result = rs->get() << 1;

    // Flags
    this->flags->neg = result < 0;
    this->flags->zero = result == 0;
    this->flags->carry = (rs->get() >> 15) & 1;
    this->flags->overflow = 0;
    
    return result;
}
