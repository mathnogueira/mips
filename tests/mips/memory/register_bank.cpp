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
	Register *r = bank.getRegister(7);
	ASSERT_STREQ("r7", r->getName());
	r = bank.getRegister(1);
	ASSERT_STREQ("r1", r->getName());
}
