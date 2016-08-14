#include <mips/instructions/format_I/lsl.hpp>
#include <mips/circuits/full_adder.hpp>

using namespace MIPS;

bit16_t LslInstruction::execute() {
    
    return (int) ((unsigned int) rs->get() << 1);
}
