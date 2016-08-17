#include <mips/memory/register_bank.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

RegisterBank::RegisterBank(ControlUnit &controlUnit) : control(controlUnit)  {
	this->iRegister[0] = new Register("r0");
	this->iRegister[1] = new Register("r1");
	this->iRegister[2] = new Register("r2");
	this->iRegister[3] = new Register("r3");
	this->iRegister[4] = new Register("r4");
	this->iRegister[5] = new Register("r5");
	this->iRegister[6] = new Register("r6");
	this->iRegister[7] = new Register("r7");
    this->pc = new Register("pc");
}

RegisterBank::~RegisterBank(){
	for (unsigned char i = 0; i < 8; ++i) {
		delete this->iRegister[i];
	}
}

Register* RegisterBank::getRegister(bit8_t id) {
	return this->iRegister[id];
}

Register* RegisterBank::getPC() {
    return pc;
}

void RegisterBank::write(bit16_t result, bit8_t rd) {
	if (control.regwrite == false)
		return;
    getRegister(rd)->put(result);
}
