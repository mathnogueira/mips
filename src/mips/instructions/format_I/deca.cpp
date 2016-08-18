#include <mips/instructions/format_I/deca.hpp>
#include <mips/circuits/full_adder.hpp>
#include <mips/circuits/signal_inversor.hpp>

using namespace MIPS;

bit16_t DecaInstruction::execute() {
    FullAdder sum;
    SignalInversor inversor;
    bit16_t result = sum.add(this->rs->get(), 0, inversor.invert(1));
    
    // Flags
    this->flags->neg = result < 0;
    this->flags->zero = result == 0;
    // TO DO this->flags->carry = 0;
    this->flags->overflow = sum.overflow();
    
    return result;
}
