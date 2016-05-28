#include <mips/memory/register_bank.hpp>
#include <mips/memory/register.hpp>

using namespace MIPS;

RegisterBank::RegisterBank() {
	this->iRegister[0] = new Register("zero");
	this->iRegister[1] = new Register("at");
	this->iRegister[2] = new Register("v0");
	this->iRegister[3] = new Register("v1");
	this->iRegister[4] = new Register("a0");
	this->iRegister[5] = new Register("a1");
	this->iRegister[6] = new Register("a2");
	this->iRegister[7] = new Register("a3");
	this->iRegister[8] = new Register("t0");
	this->iRegister[9] = new Register("t1");
	this->iRegister[10] = new Register("t2");
	this->iRegister[11] = new Register("t3");
	this->iRegister[12] = new Register("t4");
	this->iRegister[13] = new Register("t5");
	this->iRegister[14] = new Register("t6");
	this->iRegister[15] = new Register("t7");
	this->iRegister[16] = new Register("s0");
	this->iRegister[17] = new Register("s1");
	this->iRegister[18] = new Register("s2");
	this->iRegister[19] = new Register("s3");
	this->iRegister[20] = new Register("s4");
	this->iRegister[21] = new Register("s5");
	this->iRegister[22] = new Register("s6");
	this->iRegister[23] = new Register("s7");
	this->iRegister[24] = new Register("t8");
	this->iRegister[25] = new Register("t9");
	this->iRegister[26] = new Register("k0");
	this->iRegister[27] = new Register("k1");
	this->iRegister[28] = new Register("gp");
	this->iRegister[29] = new Register("sp");
	this->iRegister[30] = new Register("fp");
	this->iRegister[31] = new Register("ra");
}

RegisterBank::~RegisterBank() {
	for (unsigned char i = 0; i < 32; ++i) {
		delete this->iRegister[i];
	}
}

Register* RegisterBank::getRegister(bit8_t id) {
	return this->iRegister[id];
}
