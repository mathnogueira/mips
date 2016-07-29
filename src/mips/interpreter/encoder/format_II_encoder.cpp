#include <mips/interpreter/encoder/format_II_encoder.hpp>

using namespace MIPS;

void FormatIIEncoder::parse(std::vector<char*> &params) {
	std::cout << params.at(0) << std::endl;
}

instruction_t FormatIIEncoder::encode() {
	return 0;
}
