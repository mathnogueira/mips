#include <mips/instructions/format_IV/jf_negzero.hpp>

using namespace MIPS;

bit16_t JfNegzeroInstruction::execute() {
    return !(flags.zero || flags.neg);
}
