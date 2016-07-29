#include <mips/interpreter/encoder/format_VII_encoder.hpp>

using namespace MIPS;

void FormatVIIEncoder::parse(std::vector<char*> &params) {
	std::cout << params.at(0) << std::endl;
}

instruction_t FormatVIIEncoder::encode() {
	return 0;
}
