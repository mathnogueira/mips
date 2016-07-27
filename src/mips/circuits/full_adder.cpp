#include <mips/circuits/full_adder.hpp>
#include <cstdio>

using namespace MIPS;

FullAdder::FullAdder() {
	this->flagOverflow = false;
}

/**
 * Soma dois números de 16 bits.
 *
 * @param a primeiro parametro da soma
 * @param b segundo parametro da soma
 * @param c carry de entrada (padrão: 0)
 * @return resultado da soma entre a e b
 */
bit16_t FullAdder::add(bit16_t a, bit16_t b, bit8_t c) {
	bit8_t aBit;
	bit8_t bBit;
	bit8_t carry = c;
	bit8_t sum;
	bit16_t result = 0;
	for (bit8_t bit = 0; bit < 16; ++bit) {
		aBit = (a >> bit) & 1;
		bBit = (b >> bit) & 1;
		// soma = (a xor b) xor carry
		sum = (aBit ^ bBit) ^ carry;
		carry = (aBit & bBit) | ((aBit ^ bBit) & carry);
		result += sum << bit;
	}
	if ((a >= 0 && b >= 0 && result < 0) || (a < 0 && b < 0 && result >= 0))
		flagOverflow = true;
	return result;
}

/**
 * Verifica se houve overflow na operação de adição.
 *
 * @return true se houve overflow.
 */
bool FullAdder::overflow() {
	return flagOverflow;
}
