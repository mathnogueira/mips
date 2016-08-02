#include <gtest/gtest.h>
#include <mips/interpreter/encoder/format_VII_encoder.hpp>

using namespace MIPS;

TEST(FormatVIIEncoder, encodeLoad) {
	std::vector<char*> params;
	params.push_back((char*) "load");
	params.push_back((char*) "r1");
	params.push_back((char*) "r3");
	FormatVIIEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 19736);
}

TEST(FormatVIIEncoder, encodeStore) {
	std::vector<char*> params;
	params.push_back((char*) "store");
	params.push_back((char*) "r1");
	params.push_back((char*) "r3");
	FormatVIIEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 19864);
}
