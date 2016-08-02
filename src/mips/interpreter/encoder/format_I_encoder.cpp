#include <mips/interpreter/encoder/format_I_encoder.hpp>
#include <cstring>
#include <cstdio>

using namespace MIPS;

void FormatIEncoder::parse(std::vector<char*> &params) {
    FORMAT_DEBUG("[Codificando instrução %s do formato I]\n", params.at(0));
	char *name = params.at(0);
	this->opcode = 1;
    this->rs = 0;
    this->rt = 0;
    this->funct = 0;
	this->rd = this->getRegisterNumber(params.at(1));
    if (params.size() >= 3)
        this->rs = this->getRegisterNumber(params.at(2));
    if (params.size() == 4)
        this->rt = this->getRegisterNumber(params.at(3));
	// Define o código de função
	if (strcmp(name, "add") == 0)
		this->funct = 24;
	else if (strcmp(name, "addinc") == 0)
		this->funct = 26;
	else if (strcmp(name, "and") == 0)
		this->funct = 2;
	else if (strcmp(name, "andnota") == 0)
		this->funct = 10;
	else if (strcmp(name, "nand") == 0)
		this->funct = 3;
	else if (strcmp(name, "nor") == 0)
		this->funct = 5;
	else if (strcmp(name, "ornotb") == 0)
		this->funct = 11;
	else if (strcmp(name, "sub") == 0)
		this->funct = 25;
	else if (strcmp(name, "subdec") == 0)
		this->funct = 27;
	else if (strcmp(name, "xnor") == 0)
		this->funct = 7;
	else if (strcmp(name, "xor") == 0)
		this->funct = 6;
	else if (strcmp(name, "or") == 0)
		this->funct = 4;
	else if (strcmp(name, "asl") == 0)
		this->funct = 17;
	else if (strcmp(name, "asr") == 0)
		this->funct = 19;
	else if (strcmp(name, "deca") == 0)
		this->funct = 29;
	else if (strcmp(name, "inca") == 0)
		this->funct = 28;
	else if (strcmp(name, "lsl") == 0)
		this->funct = 16;
	else if (strcmp(name, "lsr") == 0)
		this->funct = 18;
	else if (strcmp(name, "passa") == 0)
		this->funct = 9;
	else if (strcmp(name, "passanota") == 0)
		this->funct = 8;
	else if (strcmp(name, "zeros") == 0)
		this->funct = 0;
	else if (strcmp(name, "ones") == 0)
		this->funct = 1;
}

instruction_t FormatIEncoder::encode() {
    MESSAGE("Opcode\tRD\tRS\tRT\tFunct\n");
    FORMAT_DEBUG("%d\t%d\t%d\t%d\t%d\n\n", opcode, rd, rs, rt, funct);
	instruction_t instruction = 0;
	instruction |= (opcode << 14);
	instruction |= (rd << 11);
	instruction |= (funct << 6);
	instruction |= (rs << 3);
	instruction |= (rt << 0);
	return instruction;
}
