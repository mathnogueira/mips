#include <mips/instructions/format_I/add.hpp>
#include <mips/circuits/full_adder.hpp>

using namespace MIPS;

bit16_t AddInstruction::execute() {
    FullAdder sum;
    
    bit16_t result = sum.add(this->rs->get(), this->rt->get(), 0);
    
    return result;
}
