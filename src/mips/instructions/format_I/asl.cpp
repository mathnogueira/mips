#include <mips/instructions/format_I/asl.hpp>
#include <mips/circuits/full_adder.hpp>

using namespace MIPS;

bit16_t AslInstruction::execute() {
    return rs->get() << 1;
}
