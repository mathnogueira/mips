#include <gtest/gtest.h>
#include <mips/circuits/signal_extender.hpp>

using namespace MIPS;

TEST(SignalExtender, positiveNumber) {
	bit8_t n = 120;
	bit16_t extended = SignalExtender::extend(n);
	ASSERT_EQ(extended, 120);
}

TEST(SignalExtender, negativeNumber) {
	bit8_t n = -120;
	bit16_t extended = SignalExtender::extend(n);
	ASSERT_EQ(extended, -376);
}
