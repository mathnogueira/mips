#include <mips/interpreter/encoder/encoder_factory.hpp>
#include <mips/interpreter/encoder/encoder.hpp>
#include <cstring>

using namespace MIPS;

EncoderFactory::EncoderFactory(std::vector<Label>& labels) {
	iEncoder = new IEncoder(labels);
	rEncoder = new REncoder(labels);
	jEncoder = new JEncoder(labels);
}

EncoderFactory::~EncoderFactory() {
	delete iEncoder;
	delete rEncoder;
	delete jEncoder;
}

Encoder* EncoderFactory::produce(const char *operation) {
	switch (this->getInstructionType(operation)) {
		case R:
			return rEncoder;
		case I:
			return iEncoder;
		case J:
			return jEncoder;
		default:
			return NULL;
	}
}

EncoderFactory::InstructionType EncoderFactory::getInstructionType(const char *instruction) {
	if (isTypeR(instruction))
		return R;
	if (isTypeI(instruction))
		return I;
	if (isTypeJ(instruction))
		return J;
}

static const char* rInstructions[] = {
	"add", "addu", "and", "div", "divu", "jr", "mfhi", "mflo", "mfc0", "mult", "multu", "nor",
	"xor", "or", "slt", "sltu", "sll", "srl", "sra", "sub", "subu"
};
static const char* iInstructions[] = {
	"addi", "addiu", "andi", "beq", "bne", "lbu", "lhu", "lui", "lw", "ori", "sb", "sh", "slti",
	"sltiu", "sw"
};
static const char* jInstructions[] = {
	"j", "jal"
};

bool EncoderFactory::isTypeR(const char* instruction) {
	unsigned char size = sizeof(rInstructions)/sizeof(*rInstructions);
	for (unsigned char i = 0; i < size; ++i) {
		if (strcmp(instruction, rInstructions[i]) == 0)
			return true;
	}
	return false;
}

bool EncoderFactory::isTypeI(const char* instruction) {
	unsigned char size = sizeof(iInstructions)/sizeof(*iInstructions);
	for (unsigned char i = 0; i < size; ++i) {
		if (strcmp(instruction, iInstructions[i]) == 0)
			return true;
	}
	return false;
}

bool EncoderFactory::isTypeJ(const char* instruction) {
	unsigned char size = sizeof(jInstructions)/sizeof(*jInstructions);
	for (unsigned char i = 0; i < size; ++i) {
		if (strcmp(instruction, jInstructions[i]) == 0)
			return true;
	}
	return false;
}
