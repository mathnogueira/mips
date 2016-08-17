#include <mips/units/control.hpp>

using namespace MIPS;

ControlUnit::ControlUnit() {}

ControlUnit::~ControlUnit() {}

void ControlUnit::reset() {
	regwrite = false;
	memWrite = false;
	memRead = false;
	branch = false;
	jump = false;
	regDst = false;
}
