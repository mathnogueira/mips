#include <mips/interpreter/encoder/format_III_encoder.hpp>

using namespace MIPS;

void FormatIIIEncoder::parse(std::vector<char*> &params) {
	std::cout << params.at(0) << std::endl;
}

instruction_t FormatIIIEncoder::encode() {
	return 0;
}
