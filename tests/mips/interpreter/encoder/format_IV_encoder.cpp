#include <gtest/gtest.h>
#include <mips/interpreter/encoder/format_IV_encoder.hpp>

using namespace MIPS;

TEST(FormatIVEncoder, encodeJF_neg) {
	std::vector<char*> params;
	params.push_back((char*) "jf.neg");
	params.push_back((char*) "125");
	FormatIVEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 1149);
}

TEST(FormatIVEncoder, encodeNegativeJF_neg) {
	std::vector<char*> params;
	params.push_back((char*) "jf.neg");
	params.push_back((char*) "-128");
	FormatIVEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 1152);
}

TEST(FormatIVEncoder, encodeJF_zero) {
	std::vector<char*> params;
	params.push_back((char*) "jf.zero");
	params.push_back((char*) "125");
	FormatIVEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 1405);
}

TEST(FormatIVEncoder, encodeJF_carry) {
	std::vector<char*> params;
	params.push_back((char*) "jf.carry");
	params.push_back((char*) "125");
	FormatIVEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 1661);
}

TEST(FormatIVEncoder, encodeJF_negzero) {
	std::vector<char*> params;
	params.push_back((char*) "jf.negzero");
	params.push_back((char*) "125");
	FormatIVEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 1917);
}

TEST(FormatIVEncoder, encodeJF_true) {
	std::vector<char*> params;
	params.push_back((char*) "jf.true");
	params.push_back((char*) "125");
	FormatIVEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 125);
}

TEST(FormatIVEncoder, encodeJF_overflow) {
	std::vector<char*> params;
	params.push_back((char*) "jf.overflow");
	params.push_back((char*) "128");
	FormatIVEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 896);
}

TEST(FormatIVEncoder, encodeJT_neg) {
	std::vector<char*> params;
	params.push_back((char*) "jt.neg");
	params.push_back((char*) "125");
	FormatIVEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 5245);
}

TEST(FormatIVEncoder, encodeJT_zero) {
	std::vector<char*> params;
	params.push_back((char*) "jt.zero");
	params.push_back((char*) "125");
	FormatIVEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 5501);
}

TEST(FormatIVEncoder, encodeJT_carry) {
	std::vector<char*> params;
	params.push_back((char*) "jt.carry");
	params.push_back((char*) "125");
	FormatIVEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 5757);
}

TEST(FormatIVEncoder, encodeJT_negzero) {
	std::vector<char*> params;
	params.push_back((char*) "jt.negzero");
	params.push_back((char*) "125");
	FormatIVEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 6013);
}

TEST(FormatIVEncoder, encodeJT_true) {
	std::vector<char*> params;
	params.push_back((char*) "jt.true");
	params.push_back((char*) "125");
	FormatIVEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 4221);
}

TEST(FormatIVEncoder, encodeJT_overflow) {
	std::vector<char*> params;
	params.push_back((char*) "jt.overflow");
	params.push_back((char*) "128");
	FormatIVEncoder encoder;
	encoder.parse(params);
	instruction_t instruction = encoder.encode();
	ASSERT_EQ(instruction, 4992);
}
