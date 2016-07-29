#include <gtest/gtest.h>
#include <mips/circuits/full_SubDec.hpp>

using namespace MIPS;

TEST(FullSubDec, subdecPositives) {
	FullSubDec subd;
	bit16_t a = 20;
	bit16_t b = 10;

	bit16_t result = subd.subdec(a, b);
	ASSERT_EQ(result, 9);
	ASSERT_FALSE(subd.overflow());

}

TEST(FullSubDec, subdecPositivesNegatives) {
	FullSubDec subd;
	bit16_t a = 5;
	bit16_t b = -20;

	bit16_t result = subd.subdec(a, b);
	ASSERT_EQ(result, 24);
	ASSERT_FALSE(subd.overflow());

}

TEST(FullSubDec, subdecNegativePositives) {
	FullSubDec subd;
	bit16_t a = -10;
	bit16_t b = 30;

	bit16_t result = subd.subdec(a, b);
	ASSERT_EQ(result, -41);
	ASSERT_FALSE(subd.overflow());

}

TEST(FullSubDec, subPositiveOverflow) {
	FullSubDec subd;
	bit16_t a = 32767;
	bit16_t b = 1;

	bit16_t result = subd.subdec(a, b);
	ASSERT_EQ(result, 32765);
	ASSERT_TRUE(subd.overflow());
}

TEST(FullSubDec, subNegativeOverflow) {
	FullSubDec subd;
	bit16_t a = -32767;
	bit16_t b = -1;

	bit16_t result = subd.subdec(a, b);
	ASSERT_EQ(result, -32767);
	ASSERT_TRUE(subd.overflow());
}