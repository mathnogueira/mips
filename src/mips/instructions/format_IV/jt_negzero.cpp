#include <mips/instructions/format_IV/jt_negzero.hpp>

using namespace MIPS;

bit16_t JtNegzeroInstruction::execute() {
    return (flags.zero || flags.neg);
}
