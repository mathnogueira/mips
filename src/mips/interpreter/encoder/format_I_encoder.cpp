#include <mips/interpreter/encoder/format_I_encoder.hpp>
#include <cstring>
#include <cstdio>

using namespace MIPS;

void FormatIEncoder::parse(std::vector<char*> &params) {
	char *name = params.at(0);
	this->opcode = 1;
	this->rd = this->getRegisterNumber(params.at(1));
	if (strcmp(name, "zero") && strcmp(name, "ones")) {
		this->rs = this->getRegisterNumber(params.at(2));
	} if (strcmp(name, "asl") &&
		strcmp(name, "asr") &&
		strcmp(name, "deca") &&
		strcmp(name, "inca") &&
		strcmp(name, "lsl") &&
		strcmp(name, "lsr") &&
		strcmp(name, "passa") &&
		strcmp(name, "passanota") &&
		strcmp(name, "zero") &&
		strcmp(name, "ones")) {
			this->rt = this->getRegisterNumber(params.at(3));
	}
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
	instruction_t instruction = 0;
	printf("Passo 0: %04x ==> ", instruction);
	PRINT_BIN(instruction);
	instruction |= (opcode << 14);
	printf("Passo 1: %04x ==> ", instruction);
	PRINT_BIN(instruction);
	instruction |= (rd << 11);
	printf("Passo 2: %04x ==> ", instruction);
	PRINT_BIN(instruction);
	instruction |= (funct << 6);
	printf("Passo 3: %04x ==> ", instruction);
	PRINT_BIN(instruction);
	instruction |= (rs << 3);
	printf("Passo 4: %04x ==> ", instruction);
	PRINT_BIN(instruction);
	instruction |= (rt << 0);
	printf("Passo 5: %04x ==> ", instruction);
	PRINT_BIN(instruction);
	return instruction;
}
