#include <mips/instructions/format_V/j.hpp>

using namespace MIPS;

void JumpInstruction::updateControl(ControlUnit &control) {
	control.jump = true;
	control.branch = false;
	control.memRead = false;
	control.memWrite = false;
	control.regwrite = false;
}

bit16_t JumpInstruction::execute() {
	return 1;
}
