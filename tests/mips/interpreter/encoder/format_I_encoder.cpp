#include <gtest/gtest.h>
#include <mips/interpreter/encoder/format_I_encoder.hpp>
#include <vector>

using namespace MIPS;

TEST(FormatIEncoder, encodeAdd) {
	std::vector<char*> params;
	params.push_back((char*) "add");
	params.push_back((char*) "r0");
	params.push_back((char*) "r1");
	params.push_back((char*) "r3");
	FormatIEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 0x460b);
}

TEST(FormatIEncoder, encodeSub) {
	std::vector<char*> params;
	params.push_back((char*) "addinc");
	params.push_back((char*) "r0");
	params.push_back((char*) "r1");
	params.push_back((char*) "r3");
	FormatIEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 0x468b);
}
