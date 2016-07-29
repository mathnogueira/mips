#include <mips/interpreter/encoder/format_VI_encoder.hpp>

using namespace MIPS;

void FormatVIEncoder::parse(std::vector<char*> &params) {
	std::cout << params.at(0) << std::endl;
}

instruction_t FormatVIEncoder::encode() {
	return 0;
}
