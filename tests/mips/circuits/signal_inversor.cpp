#include <gtest/gtest.h>
#include <mips/core.hpp>
#include <mips/circuits/signal_inversor.hpp>

using namespace MIPS;

TEST(SignalInversor, invertPositiveNumber) {
	bit16_t original = 86;
	SignalInversor inversor;
	bit16_t inverted = inversor.invert(original);
	ASSERT_EQ(inverted, -86);
}

TEST(SignalInversor, invertNegativeNumber) {
	bit16_t original = -77;
	SignalInversor inversor;
	bit16_t inverted = inversor.invert(original);
	ASSERT_EQ(inverted, 77);
}
