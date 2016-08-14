#include <mips/instructions/format_VII/load.hpp>
using namespace MIPS;

bit16_t LoadInstruction::execute() {
    this->rt->put(this->memory->read(this->rs->get()));
    
    return 1;
}
