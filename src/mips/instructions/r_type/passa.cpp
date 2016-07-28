#include <mips/instructions/r_type/passa.hpp>

using namespace MIPS;

void PassaInstruction::execute() {
	bit16_t ra = this->rd->get();
	this->rs->put(ra);
}
