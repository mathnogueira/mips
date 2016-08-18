#include <mips/instructions/format_VI/jal.hpp>

using namespace MIPS;

bit16_t JalInstruction::execute() {
    this->rs->put(this->pc->get());
    this->pc->put(this->rt->get());

    return 1;
}
