#include <mips/instructions/format_I/addinc.hpp>
#include <mips/circuits/full_adder.hpp>

using namespace MIPS;

bit16_t AddIncInstruction::execute() {
    FullAdder sum;
    
    //bit16_t result = (sum.add(this->rs->get(), this->rt->get(), 0)) + 1;
    
    bit16_t result = sum.add(this->rs->get(), this->rt->get(), 0);
    result = sum.add(result, 1, 0);
    
    return result;
}
