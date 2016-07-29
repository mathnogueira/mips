/**
 * \file signal_inversor.hpp
 *
 * Inversor de sinal em números que utilizam a representação de complemento de 2.
 */
#pragma once

#include <mips/core.hpp>

namespace MIPS {

/**
 * Classe responsável por realizar inversão de sinal de 16 bits.
 *
 * @author Matheus Nogueira
 */
class SignalInversor {

public:

	/**
	 * Cria um novo somador.
	 */
	SignalInversor();

	/**
	 * Inverte o sinal de um número.
	 *
	 * @param num número que terá seu sinal invertido.
	 * @return número com o sinal invertido.
	 */
	bit16_t invert(bit16_t num);

};

} // namespace
