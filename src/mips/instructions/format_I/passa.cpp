#include <mips/instructions/format_I/passa.hpp>

using namespace MIPS;

void PassaInstruction::execute() {
	bit16_t ra = this->rd->get();
	this->rs->put(ra);
}
