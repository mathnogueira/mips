#include <mips/instructions/format_II/loadlit.hpp>
#include <mips/circuits/signal_extender.hpp>

using namespace MIPS;

bit16_t LoadlitInstruction::execute() {
	bit16_t extended = SignalExtender::extend(this->offset, 11);
	return extended;
}
