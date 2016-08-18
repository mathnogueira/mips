#include <mips/instructions/format_VI/jr.hpp>

using namespace MIPS;

bit16_t JrInstruction::execute() {
    this->pc->put(this->rs->get());
    
    return 1;
}
