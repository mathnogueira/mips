#include <gtest/gtest.h>
#include <mips/interpreter/encoder/format_V_encoder.hpp>

using namespace MIPS;

TEST(FormatVEncoder, encodeJumpPositiveOffset) {
	std::vector<char*> params;
	params.push_back("j");
	params.push_back("1067");
	FormatVEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, -31701);
}

TEST(FormatVEncoder, encodeJumpNegativeOffset) {
	std::vector<char*> params;
	params.push_back("j");
	params.push_back("-1067");
	FormatVEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, -29739);
}
