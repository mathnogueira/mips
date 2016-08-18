#include <mips/instructions/format_IV/jt_overflow.hpp>

using namespace MIPS;

bit16_t JtOverflowInstruction::execute() {
    return (flags.overflow == 1);
}
