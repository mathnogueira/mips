#include <mips/interpreter/encoder/format_IV_encoder.hpp>

using namespace MIPS;

void FormatIVEncoder::parse(std::vector<char*> &params) {
	std::cout << params.at(0) << std::endl;
}

instruction_t FormatIVEncoder::encode() {
	return 0;
}
