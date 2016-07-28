#include <mips/instructions/format_II/loadlit.hpp>
#include <mips/circuits/signal_extender.hpp>

using namespace MIPS;

void LoadlitInstruction::execute() {
	bit16_t extended = SignalExtender::extend(this->offset, 11);
	this->rd->put(extended);
}
