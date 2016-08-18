#include <mips/instructions/format_VII/load.hpp>
using namespace MIPS;

bit16_t LoadInstruction::execute() {
    return this->memory->read(this->rs->get());
}
