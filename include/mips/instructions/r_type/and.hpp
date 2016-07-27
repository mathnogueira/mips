/**
 *
 *
 * Operador and de 16 bits.
 * Referencia: http://isweb.redwoods.edu/instruct/calderwoodd/diglogic/and.htm
 */
#pragma once

#include <mips//core.hpp>

namespace MIPS {

/**
 * Classe responsavel pela operacao and bit a bit de 16 bits.
 *
 * @author Lucas Fonseca dos Santos
 */
class AndInstruction {

public:

	AndInstruction();

	/**
	 * Executa uma operacao and bit a bit em um numero de 16 bits
	 *
	 * @param a primeiro parametro da operacao
	 * @param b segundo parametro da operacao
	 * @return resultado da operacao and entre a e b
	 */
	bit16_t and(bit16_t a, bit16_t b, bit8_t c = 0);

	/**
	 * Verifica se houve overflow na operação de adição.
	 *
	 * @return true se houve overflow.
	 */
	bool overflow();

private:

	/**
	 * Flag que identifica carry no ultimo bit da operação.
	 */
	bool flagOverflow;

};

} // namespace
