#include <mips/instructions/format_I/addinc.hpp>
#include <mips/circuits/full_adder.hpp>

using namespace MIPS;

bit16_t AddIncInstruction::execute() {
    FullAdder sum;
    bit16_t result = sum.add(this->rs->get(), this->rt->get(), 1);
    
    // Flags
    this->flags->neg = result < 0;
    this->flags->zero = result == 0;
    this->flags->carry = sum.carry();
    this->flags->overflow = sum.overflow();
    
    return result;
}
