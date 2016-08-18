#include <mips/instructions/format_II/loadlit.hpp>
#include <mips/circuits/signal_extender.hpp>

using namespace MIPS;

bit16_t LoadlitInstruction::execute() {
	PRINT_BIN(offset);
	bit16_t extended = SignalExtender::extend(this->offset, 11);
	PRINT_BIN(extended);
	return extended;
}
