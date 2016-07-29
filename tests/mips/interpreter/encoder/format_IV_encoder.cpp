#include <gtest/gtest.h>
#include <mips/interpreter/encoder/format_IV_encoder.hpp>

using namespace MIPS;

TEST(FormatIVEncoder, encodeJT_zero) {
	std::vector<char*> params;
	params.push_back("jf.zero");
	params.push_back("125");
	FormatIVEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 1405);
}

TEST(FormatIVEncoder, encodeJT_overflow) {
	std::vector<char*> params;
	params.push_back("jf.overflow");
	params.push_back("128");
	FormatIVEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 896);
}
