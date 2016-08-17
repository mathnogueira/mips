#include <mips/instructions/format_I/lsr.hpp>
#include <mips/circuits/full_adder.hpp>

using namespace MIPS;

bit16_t LsrInstruction::execute() {

    return (rs->get() >> 1) & 0x7fff;
}
