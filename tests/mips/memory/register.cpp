#include <gtest/gtest.h>
#include <mips/core.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(Register, constructor) {
	Register r("v0");
	ASSERT_STREQ("v0", r.getName());
	ASSERT_EQ(0, r.get());
}

TEST(Register, setValue) {
	Register r("s0");
	r.put(32);
	ASSERT_EQ(32, r.get());
}

TEST(Register, changeValue) {
	Register r("s0");
	r.put(32);
	r.put(r.get() + 32);
	ASSERT_EQ(64, r.get());
}
