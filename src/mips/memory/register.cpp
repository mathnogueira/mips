#include <mips/memory/register.hpp>

using namespace MIPS;

Register::Register(const char* name) {
	this->name = name;
	this->content = 0;
}

Register::~Register() {}

void Register::put(bit16_t value) {
	content = value;
	DEBUG("Atualizando o " << name << " com o valor " << content << std::endl);
}

bit16_t Register::get() {
	return this->content;
}

const char* Register::getName() {
	return this->name;
}
