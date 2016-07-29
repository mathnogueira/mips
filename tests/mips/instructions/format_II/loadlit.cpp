#include <gtest/gtest.h>
#include <mips/instructions/format_II/loadlit.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(LoadlitInstruction, loadPositive) {
	Register rd("s0");
	LoadlitInstruction loadlit(0, &rd, 15);
	bit16_t result = loadlit.execute();
	ASSERT_EQ(result, 15);
}

TEST(LoadlitInstruction, loadNegative) {
	Register rd("s1");
	LoadlitInstruction loadlit(0, &rd, -101);
	bit16_t result = loadlit.execute();
	ASSERT_EQ(result, -101);
}
