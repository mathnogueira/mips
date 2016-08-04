#include <mips/instructions/format_IV/jt_zero.hpp>

using namespace MIPS;

bit16_t JtZeroInstruction::execute() {
    return flags.zero;
}
