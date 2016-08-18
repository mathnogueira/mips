#include <mips/instructions/format_IV/jf_carry.hpp>

using namespace MIPS;

bit16_t JfCarryInstruction::execute() {
    return !(flags.carry == 1);
}
