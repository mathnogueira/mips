#include <mips/instructions/format_I/ornotb.hpp>

using namespace MIPS;

bit16_t OrnotbInstruction::execute() {
	bit16_t rs = this->rs->get();
	bit16_t rt = this->rt->get();
	bit16_t result = rs | !(rt);
	return result;
}
