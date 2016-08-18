#include <mips/instructions/format_I/asl.hpp>
#include <mips/circuits/full_adder.hpp>

using namespace MIPS;

bit16_t AslInstruction::execute() {
    bit16_t result = rs->get() << 1;
    
    // Flags
    this->flags->neg = result < 0;
    this->flags->zero = result == 0;
    this->flags->carry = (this->rs->get() >> 15) & 1;
    this->flags->overflow = ((rs->get() >> 15) & 1) ^ ((rs->get() >> 14) & 1);
    
    return result;
}
