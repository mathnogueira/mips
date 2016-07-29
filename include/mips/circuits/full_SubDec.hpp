/**
 * \file fullSubDec.hpp
 *
 * Subtração e decremento de 16 bits.
 * Referencia: http://isweb.redwoods.edu/instruct/calderwoodd/diglogic/full.htm
 */
#pragma once

#include <mips//core.hpp>

namespace MIPS {

/**
 * Classe responsável por realizar as operações de subtração e decremento de 16 bits.
 *
 * @author Lucas Pereira
 */
class FullSubDec {

public:

	/**
	 * Cria uma nova subtração.
	 */
	FullSubDec();

	/**
	 * Subtrai e decrementa dois números de 16 bits.
	 *
	 * @param a primeiro parametro da soma
	 * @param b segundo parametro da soma
	 * @param c carry de entrada (padrão: 0)
	 * @return resultado da subtrai entre a e b e decrementa 1 inteiro
	 */
	bit16_t subdec(bit16_t a, bit16_t b, bit8_t c = 0);

	/**
	 * Verifica se houve overflow na operação de subtração.
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
