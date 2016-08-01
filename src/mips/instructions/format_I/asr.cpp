#include <mips/instructions/format_I/asr.hpp>
#include <mips/circuits/full_adder.hpp>

using namespace MIPS;

bit16_t AsrInstruction::execute() {
    return rs->get() >> 1;
}
