#include <mips/circuits/signal_extender.hpp>
#include <cstdio>
#include <iostream>

using namespace MIPS;

bit16_t SignalExtender::extend(bit16_t num, bit8_t bits) {
	bit16_t bitValue = (num >> bits) & 1;
	bit16_t extended = 0;
	for (bit8_t bit = bits; bit < 16; ++bit) {
		extended += (bitValue << bit);
	}
	extended |= num;
	return extended;
}
