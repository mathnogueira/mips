#include <mips/instructions/format_IV/jt_carry.hpp>

using namespace MIPS;

bit16_t JtCarryInstruction::execute() {
    return (flags.carry == 1);
}
