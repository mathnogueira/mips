#include <mips/instructions/format_IV/jf_overflow.hpp>

using namespace MIPS;

bit16_t JfOverflowInstruction::execute() {
    return !(flags.overflow == 1);
}
