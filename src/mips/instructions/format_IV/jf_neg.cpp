#include <mips/instructions/format_IV/jf_neg.hpp>

using namespace MIPS;

bit16_t JfNegInstruction::execute() {
    return !(flags.neg);
}
