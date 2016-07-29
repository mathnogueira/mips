#include <mips/instructions/format_I/ornotb.hpp>

using namespace MIPS;

void OrnotbInstruction::execute() {
	bit16_t rs = this->rs->get();
	bit16_t rt = this->rt->get();
	bit16_t result = rs | !(rt);
	this->rd->put(result);
}
