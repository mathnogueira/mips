#include <gtest/gtest.h>
#include <mips/instructions/format_I/asr.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

TEST(AsrInstruction, positiveNumber) {
	Register rs("s0");
	AsrInstruction asr(0, &rs, NULL, 0, 0);
	struct ALUFlags flags;
	asr.setALUFlags(flags);
	rs.put(6);
	ASSERT_EQ(asr.execute(), 3);
}

TEST(AsrInstruction, positiveNumberOdd) {
	Register rs("s0");
	AsrInstruction asr(0, &rs, NULL, 0, 0);
	struct ALUFlags flags;
	asr.setALUFlags(flags);
	rs.put(9);
	ASSERT_EQ(asr.execute(), 4);
}

TEST(AsrInstruction, NegativeNumber) {
	Register rs("s0");
	AsrInstruction asr(0, &rs, NULL, 0, 0);
	struct ALUFlags flags;
	asr.setALUFlags(flags);
	rs.put(-6);
	ASSERT_EQ(asr.execute(), -3);
}

TEST(AsrInstruction, NegativeNumberOdd) {
	Register rs("s0");
	AsrInstruction asr(0, &rs, NULL, 0, 0);
	struct ALUFlags flags;
	asr.setALUFlags(flags);
	rs.put(-9);
	ASSERT_EQ(asr.execute(), -5);
}
