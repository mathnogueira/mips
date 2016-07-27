#include <gtest/gtest.h>
#include <mips/circuits/full_adder.hpp>

using namespace MIPS;

TEST(FullAdder, sumPositives) {
	FullAdder adder;
	bit16_t a = 21;
	bit16_t b = 9;

	bit16_t result = adder.add(a, b);
	ASSERT_EQ(result, 30);
	ASSERT_FALSE(adder.overflow());
}

TEST(FullAdder, sumPositiveNegative) {
	FullAdder adder;
	bit16_t a = 21;
	bit16_t b = -12;

	bit16_t result = adder.add(a, b);
	ASSERT_EQ(result, 9);
	ASSERT_FALSE(adder.overflow());
}

TEST(FullAdder, sumPositiveOverflow) {
	FullAdder adder;
	bit16_t a = 65535;
	bit16_t b = 1;

	bit16_t result = adder.add(a, b);
	ASSERT_EQ(result, 0);
	ASSERT_TRUE(adder.overflow());
}

TEST(FullAdder, sumNegativeOverflow) {
	FullAdder adder;
	bit16_t a = -32768;
	bit16_t b = -1;

	bit16_t result = adder.add(a, b);
	ASSERT_EQ(result, 32767);
	ASSERT_TRUE(adder.overflow());
}

TEST(FullAdder, sumUsingCarry) {
	FullAdder adder;
	bit16_t a = 16;
	bit16_t b = 8;

	bit16_t result = adder.add(a, b, 1);
	ASSERT_EQ(result, 25);
	ASSERT_FALSE(adder.overflow());
}
