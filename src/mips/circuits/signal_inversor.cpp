#include <mips/circuits/signal_inversor.hpp>

using namespace MIPS;

SignalInversor::SignalInversor() {}

bit16_t SignalInversor::invert(bit16_t num) {
	bit8_t bit;
	bit16_t result = 0;
	for (bit8_t i = 0; i < 16; ++i) {
		bit = (num >> i) & 1;
		result |= (!bit) << i;
	}
	return result + 1;
}
