#include <mips/interpreter/encoder/encoder.hpp>

using namespace MIPS;

Encoder::Encoder(std::vector<Label>& labels, const char *type) : mLabels(labels), mType(type) {

}

const char* Encoder::getType() {
	return mType;
}
