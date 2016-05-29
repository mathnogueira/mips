#include <gtest/gtest.h>
#include <mips/interpreter/encoder/encoder.hpp>
#include <mips/interpreter/label.hpp>
#include <vector>

using namespace MIPS;

TEST(Encoder, getOpCode) {
	// Classe auxiliar para acessar os metodos protegidos
	class EncoderTest : public Encoder {
	public:
		void test() {
			struct InstructionInfo info;
			info = getInstructionInfo((char*) "j");
			EXPECT_EQ(info.opcode, 0x02);
			info = getInstructionInfo((char*) "xor");
			EXPECT_EQ(info.opcode, 0x00);
			EXPECT_EQ(info.funct, 0x26);
			info = getInstructionInfo((char*) "bne");
			EXPECT_EQ(info.opcode, 0x05);
		}

		// Irrelevante para o teste, mas necessário por causa da herança
		// feita com o Encoder.
		EncoderTest(std::vector<Label>& labels) : Encoder(labels, "I") {}
		instruction32_t encode(std::vector<char*>& params) {
			return 0;
		}
	};

	std::vector<Label> fake;
	EncoderTest test(fake);
	test.test();
	SUCCEED();
}
