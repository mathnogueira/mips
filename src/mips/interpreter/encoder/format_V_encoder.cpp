#include <mips/interpreter/encoder/format_V_encoder.hpp>

using namespace MIPS;

void FormatVEncoder::parse(std::vector<char*> &params) {
	std::cout << params.at(0) << std::endl;
}

instruction_t FormatVEncoder::encode() {
	return 0;
}
