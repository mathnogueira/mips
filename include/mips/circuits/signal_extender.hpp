/**
 * \file signal_extender.hpp
 *
 * Estensor de sinal. Converte um número para 16 bits.
 */
#pragma once

#include <mips/core.hpp>

namespace MIPS {

/**
 * Circuito responsável por extender um sinal para 16 bits.
 *
 * @author Matheus Nogueira
 */
class SignalExtender {

public:

	/**
	 * Extende o sinal de um número.
	 *
	 * @param num número que será extendido.
	 * @param bits número de bits do número de entrada. (Padrão: 8)
	 * @return número de 16 bits
	 */
	static bit16_t extend(bit16_t num, bit8_t bits = 8);

};

} // namespace
