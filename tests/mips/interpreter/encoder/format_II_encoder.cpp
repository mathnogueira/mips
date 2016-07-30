#include <gtest/gtest.h>
#include <mips/interpreter/encoder/format_II_encoder.hpp>

using namespace MIPS;

TEST(FormatIIEncoder, encodePositiveLoadlit) {
	std::vector<char*> params;
	params.push_back((char*) "loadlit");
	params.push_back((char*) "$s4");
	params.push_back((char*) "3");
	FormatIIEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, -24573);
}

TEST(FormatIIEncoder, encodeNegativeLoadlit) {
	std::vector<char*> params;
	params.push_back((char*) "loadlit");
	params.push_back((char*) "$s7");
	params.push_back((char*) "-1");
	FormatIIEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, -16385);
}
