#include <mips/instructions/format_VI/jal.hpp>

using namespace MIPS;

bit16_t JalInstruction::execute() {
    this->rt->put(this->pc->get());
    this->pc->put(this->rs->get());
    
    return 1;
}
