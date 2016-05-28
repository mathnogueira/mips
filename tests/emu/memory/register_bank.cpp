#include <gtest/gtest.h>
#include <mips/core.hpp>
#include <mips/memory/register_bank.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(RegisterBank, constructor) {
	RegisterBank bank;
	SUCCEED();
}

TEST(RegisterBank, getRegister) {
	RegisterBank bank;
	Register *r = bank.getRegister(8);
	ASSERT_STREQ("t0", r->getName());
	r = bank.getRegister(1);
	ASSERT_STREQ("at", r->getName());
}
