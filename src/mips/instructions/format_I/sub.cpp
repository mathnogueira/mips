#include <mips/instructions/format_I/sub.hpp>
#include <mips/circuits/full_adder.hpp>
#include <mips/circuits/signal_inversor.hpp>

using namespace MIPS;

bit16_t SubInstruction::execute() {
    FullAdder adder;
    SignalInversor inversor;
    bit16_t rs = this->rs->get();
    bit16_t rt = this->rt->get();
    // Inverte RT
    rt = inversor.invert(rt);
	bit16_t result = adder.add(rs, rt);

    // Flags
    this->flags->neg = result < 0;
    this->flags->zero = result == 0;
    // TO DO this->flags->carry = 0;
    this->flags->overflow = adder.overflow();

    return result;
}
