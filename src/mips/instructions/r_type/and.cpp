#include <mips/instructions/r_type/and.hpp>
#include <cstdio>

using namespace MIPS;

AndInstruction::And() {
	this->flagOverflow = false;
}

/**
*
* @author Lucas Fonseca dos Santos
*
* Executa uma operacao and entre dois numeros de 16 bits.
*
* @param a Primeiro parametro da operacao
* @param b Segundo parametro da operacao
* @return resultado da soma  entre a e b
*/

bit16_t AndInstruction::and(bit16_t a, bit16_t b, bit8_t c) {
	bit8_t aBit;
	bit8_t bBit;
	bit8_t carry = c;
	bit8_t temp;
	bit16_t result = 0;

	//Para os 16bits do numero
	for (bit8_t bit=0; bit < 16; ++bit) {
		aBit =  (a >> bit);
		bBit = (b >> bit);
		//bit a bit, executa operador and
		temp = aBit & bBit;
		result += temp << bit;
	}
	//Se houver overflow;
	if ((a >= 0 && b >= 0 && result < 0) || (a < 0 && b < 0 && result >= 0)) {
		flagOverflow = true;
	}
	return result;
}

//Caso haja overflow, retorna true
bool AndInstruction::ouverflow() {
	return flagOverflow;
}
