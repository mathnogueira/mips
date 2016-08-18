#include <mips/instructions/format_II/loadlit.hpp>
#include <mips/circuits/signal_extender.hpp>

using namespace MIPS;

bit16_t LoadlitInstruction::execute() {
	bit16_t extended = SignalExtender::extend(this->offset, 11);
	FORMAT_DEBUG("LOADLIT: %d\n", offset);
	return extended;
}
