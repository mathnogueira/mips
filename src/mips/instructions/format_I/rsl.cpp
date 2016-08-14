#include <mips/instructions/format_I/rsl.hpp>
#include <mips/circuits/full_adder.hpp>

using namespace MIPS;

bit16_t RslInstruction::execute() {
    
    return (int) ((unsigned) rs->get() >> 1);
}
