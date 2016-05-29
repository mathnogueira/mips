#include <gtest/gtest.h>
#include <mips/interpreter/encoder/encoder_factory.hpp>
#include <mips/interpreter/encoder/encoder.hpp>
#include <mips/interpreter/label.hpp>
#include <vector>

using namespace MIPS;

TEST(EncoderFactory, create) {
	std::vector<Label> fake;
	EncoderFactory *factory = new EncoderFactory(fake);
}

TEST(EncoderFactory, createInstructionR) {
	std::vector<Label> fake;
	EncoderFactory *factory = new EncoderFactory(fake);
	Encoder *encoder = factory->produce("add");
	ASSERT_STREQ("R", encoder->getType());
}

TEST(EncoderFactory, createInstructionI) {
	std::vector<Label> fake;
	EncoderFactory *factory = new EncoderFactory(fake);
	Encoder *encoder = factory->produce("addi");
	ASSERT_STREQ("I", encoder->getType());
}

TEST(EncoderFactory, createInstructionJ) {
	std::vector<Label> fake;
	EncoderFactory *factory = new EncoderFactory(fake);
	Encoder *encoder = factory->produce("j");
	ASSERT_STREQ("J", encoder->getType());
}
