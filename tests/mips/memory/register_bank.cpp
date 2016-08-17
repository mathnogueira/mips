#include <gtest/gtest.h>
#include <mips/core.hpp>
#include <mips/memory/register_bank.hpp>
#include <mips/memory/register.hpp>
#include <mips/units/control.hpp>

using namespace MIPS;

TEST(RegisterBank, constructor) {
	ControlUnit cu;
	RegisterBank bank(cu);
	SUCCEED();
}

TEST(RegisterBank, getRegister) {
	ControlUnit cu;
	RegisterBank bank(cu);
	Register *r = bank.getRegister(7);
	ASSERT_STREQ("r7", r->getName());
	r = bank.getRegister(1);
	ASSERT_STREQ("r1", r->getName());
}
