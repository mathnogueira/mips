#include <gtest/gtest.h>
#include <mips/interpreter/encoder/format_VI_encoder.hpp>

using namespace MIPS;

TEST(FormatVIEncoder, encodeJal) {
	std::vector<char*> params;
	params.push_back("jal");
	params.push_back("$s6");
	FormatVIEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 12294);
}

TEST(FormatVIEncoder, encodeJr) {
	std::vector<char*> params;
	params.push_back("jr");
	params.push_back("$s5");
	FormatVIEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 14341);
}
