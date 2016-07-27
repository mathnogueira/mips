/**
 * \file full_adder.hpp
 *
 * Somador de 16 bits.
 * Referencia: http://isweb.redwoods.edu/instruct/calderwoodd/diglogic/full.htm
 */
#pragma once

#include <mips//core.hpp>

namespace MIPS {

/**
 * Classe responsável por realizar as operações de um somador de 16 bits.
 *
 * @author Matheus Nogueira
 */
class FullAdder {

public:

	/**
	 * Soma dois números de 16 bits.
	 *
	 * @param a primeiro parametro da soma
	 * @param b segundo parametro da soma
	 * @param c carry de entrada (padrão: 0)
	 * @return resultado da soma entre a e b
	 */
	bit16_t add(bit16_t a, bit16_t b, bit8_t c = 0);

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
