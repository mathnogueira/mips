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
    return adder.add(rs, rt);
}
