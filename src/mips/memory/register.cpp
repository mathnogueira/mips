#include <mips/memory/register.hpp>

using namespace MIPS;

Register::Register(const char* name, bool protect) {
	this->name = name;
	this->content = 0;
	this->isProtected = protect;
}

Register::~Register() {}

void Register::put(bit16_t value) {
	if (this->isProtected == false)
		this->content = value;
}

bit16_t Register::get() {
	return this->content;
}

const char* Register::getName() {
	return this->name;
}
