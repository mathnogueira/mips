#include <mips/instructions/format_I/nor.hpp>

using namespace MIPS;

bit16_t NorInstruction::execute() {
	bit16_t rs = this->rs->get();
	bit16_t rt = this->rt->get();
	bit16_t result = (!rs & !rt);
	// this->rd->put(result);
        
	// Flags
	this->neg = 0;
	this->zero = 0;
	this->carry = 0;
	this->overflow = 0;
	
        return result;
}
