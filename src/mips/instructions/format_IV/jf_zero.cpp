#include <mips/instructions/format_IV/jf_zero.hpp>

using namespace MIPS;

bit16_t JfZeroInstruction::execute() {
    return !flags.zero;
}
