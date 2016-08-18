#include <mips/instructions/format_I/inca.hpp>
#include <mips/circuits/full_adder.hpp>

using namespace MIPS;

bit16_t IncaInstruction::execute() {
    FullAdder sum;
    bit16_t result = sum.add(this->rs->get(), 0, 1);
	FORMAT_DEBUG("INCA: %d\n", rs->get());

    // Flags
    this->flags->neg = result < 0;
    this->flags->zero = result == 0;
    this->flags->carry = sum.carry();
    this->flags->overflow = sum.overflow();

    return result;
}
