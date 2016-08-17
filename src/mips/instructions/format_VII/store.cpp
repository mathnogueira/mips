#include <mips/instructions/format_VII/store.hpp>
using namespace MIPS;

bit16_t StoreInstruction::execute() {
    this->memory->write(this->rt->get(), this->rs->get());
    return 1;
}
