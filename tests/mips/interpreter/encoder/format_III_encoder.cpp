#include <gtest/gtest.h>
#include <mips/interpreter/encoder/format_III_encoder.hpp>

using namespace MIPS;

TEST(FormatIIIEncoder, encodePositiveLCL) {
	std::vector<char*> params;
	params.push_back((char*) "lcl");
	params.push_back((char*) "r4");
	params.push_back((char*) "102");
	FormatIIIEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, -8090);
}

TEST(FormatIIIEncoder, encodeNegativeLCL) {
	std::vector<char*> params;
	params.push_back((char*) "lcl");
	params.push_back((char*) "r4");
	params.push_back((char*) "-142");
	FormatIIIEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, -8078);
}

TEST(FormatIIIEncoder, encodePositiveLCH) {
	std::vector<char*> params;
	params.push_back((char*) "lch");
	params.push_back((char*) "r4");
	params.push_back((char*) "102");
	FormatIIIEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, -7066);
}

TEST(FormatIIIEncoder, encodeNegativeLCH) {
	std::vector<char*> params;
	params.push_back((char*) "lch");
	params.push_back((char*) "r4");
	params.push_back((char*) "-142");
	FormatIIIEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, -7054);
}
