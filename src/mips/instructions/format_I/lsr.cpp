#include <mips/instructions/format_I/lsr.hpp>
#include <mips/circuits/full_adder.hpp>

using namespace MIPS;

bit16_t LsrInstruction::execute() {
    
    return ((unsigned) rs->get() >> 1);
}
