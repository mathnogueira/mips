#include <mips/instructions/format_IV/jt_neg.hpp>

using namespace MIPS;

bit16_t JtNegInstruction::execute() {
    return flags.neg;
}
