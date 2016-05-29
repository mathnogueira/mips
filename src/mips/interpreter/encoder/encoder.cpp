#include <mips/interpreter/encoder/encoder.hpp>
#include <map>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace MIPS;

// Nome de todos os registradores, onde a posição dele no array é o seu número
static const char* registers[] = {
	"$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3", "$t4",
	"$t5", "$t6", "$t7", "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7", "$t8", "$t9",
	"$k0", "$k1", "$gp", "$sp", "$fp", "$ra"
};

Encoder::Encoder(std::vector<Label>& labels, const char *type) : mLabels(labels), mType(type) {
	initMap();
}

const char* Encoder::getType() {
	return mType;
}

bit8_t Encoder::getRegisterNumber(char *name) {
	bit8_t n = 32;
	for (bit8_t i = 0; i < n; ++i) {
		if (strcmp(name, registers[i]) == 0)
			return i;
	}
	return 0;
}

struct Encoder::InstructionInfo Encoder::getInstructionInfo(char *name) {
	unsigned int size = map.size();
	for (unsigned int i = 0; i < size; ++i) {
		if (strcmp(name, map.at(i).name) == 0)
			return map.at(i);
	}
}

void Encoder::initMap() {
	unsigned int nroInstructions = 38;
	struct InstructionInfo info[nroInstructions];
	// ====== Instruções do tipo R ======
	// add
	info[0].name = "add";
	info[0].opcode = (bit8_t) 0x00;
	info[0].funct = 0x20;
	// addu
	info[1].name = "addu";
	info[1].opcode = 0x00;
	info[1].funct = 0x21;
	// and
	info[2].name = "and";
	info[2].opcode = 0x00;
	info[2].funct = 0x24;
	// div
	info[3].name = "div";
	info[3].opcode = 0x00;
	info[3].funct = 0x1A;
	// divu
	info[4].name = "divu";
	info[4].opcode = 0x00;
	info[4].funct = 0x1B;
	// jr
	info[5].name = "jr";
	info[5].opcode = 0x00;
	info[5].funct = 0x08;
	// mfhi
	info[6].name = "mfhi";
	info[6].opcode = 0x00;
	info[6].funct = 0x10;
	// mflo
	info[7].name = "mflo";
	info[7].opcode = 0x00;
	info[7].funct = 0x12;
	// mfc0
	info[8].name = "mfc0";
	info[8].opcode = 0x10;
	info[8].funct = 0xff;
	// mult
	info[9].name = "mult";
	info[9].opcode = 0x00;
	info[9].funct = 0x18;
	// multu
	info[10].name = "multu";
	info[10].opcode = 0x00;
	info[10].funct = 0x19;
	// nor
	info[11].name = "nor";
	info[11].opcode = 0x00;
	info[11].funct = 0x27;
	// xor
	info[12].name = "xor";
	info[12].opcode = 0x00;
	info[12].funct = 0x26;
	// or
	info[13].name = "or";
	info[13].opcode = 0x00;
	info[13].funct = 0x25;
	// slt
	info[14].name = "slt";
	info[14].opcode = 0x00;
	info[14].funct = 0x2A;
	// sltu
	info[15].name = "sltu";
	info[15].opcode = 0x00;
	info[15].funct = 0x2B;
	// sll
	info[16].name = "sll";
	info[16].opcode = 0x00;
	info[16].funct = 0x00;
	// srl
	info[17].name = "srl";
	info[17].opcode = 0x00;
	info[17].funct = 0x02;
	// sra
	info[18].name = "sra";
	info[18].opcode = 0x00;
	info[18].funct = 0x03;
	// sub
	info[19].name = "sub";
	info[19].opcode = 0x00;
	info[19].funct = 0x22;
	// subu
	info[20].name = "subu";
	info[20].opcode = 0x00;
	info[20].funct = 0x23;
	// ===== Instruções do tipo J =====
	// j
	info[21].name = "j";
	info[21].opcode = 0x02;
	// jal
	info[22].name = "jal";
	info[22].opcode = 0x03;
	// ===== Instruções do tipo I =====
	// addi
	info[23].name = "addi";
	info[23].opcode = 0x08;
	// addiu
	info[24].name = "addiu";
	info[24].opcode = 0x09;
	// andi
	info[25].name = "addi";
	info[25].opcode = 0x0C;
	// beq
	info[26].name = "beq";
	info[26].opcode = 0x04;
	// bne
	info[27].name = "bne";
	info[27].opcode = 0x05;
	// lbu
	info[28].name = "lbu";
	info[28].opcode = 0x24;
	// lhu
	info[29].name = "lhu";
	info[29].opcode = 0x25;
	// lui
	info[30].name = "lui";
	info[30].opcode = 0x0F;
	// lw
	info[31].name = "lw";
	info[31].opcode = 0x23;
	// ori
	info[32].name = "ori";
	info[32].opcode = 0x0D;
	// sb
	info[33].name = "sb";
	info[33].opcode = 0x28;
	// sh
	info[34].name = "sh";
	info[34].opcode = 0x29;
	// slti
	info[35].name = "slti";
	info[35].opcode = 0x0A;
	// sltiu
	info[36].name = "sltiu";
	info[36].opcode = 0x0B;
	// sw
	info[37].name = "sw";
	info[37].opcode = 0x2B;
	// Insere todos no mapa.
	for (unsigned int i = 0; i < nroInstructions; ++i) {
		map.push_back(info[i]);
	}
}
