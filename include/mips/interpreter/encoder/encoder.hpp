/**
 * \file encoder.hpp
 *
 * Arquivo contendo um codificador genérico para instruções MIPS 16 bits.
 */
#pragma once

#include <mips/core.hpp>
#include <mips/interpreter/label.hpp>
#include <map>
#include <vector>

namespace MIPS {

/**
 * Classe abstrata que cria uma interface para todos os codificadores de
 * instruções MIPS 32.
 *
 * \author Matheus Nogueira
 */
class Encoder {

public:

	/**
	 * Cria um novo codificador.
	 *
	 * \param labels tabela de labels extraídos do código.
	 * \param type tipo de codificador.
	 */
	Encoder();

	/**
	 * Destroi o codificador.
	 */
	virtual ~Encoder() {}

	/**
	 * Codifica a ultima instrução que foi analisada pelo parser do codificador.
	 *
	 * \return instrução 16 bits.
	 */
	virtual instruction_t encode() = 0;

	/**
	 * Percorre a instrução em assembly e extraí os dados dela para poder
	 * montar uma instrução binária.
	 *
	 * \param params parametros da instrução.
	 */
	virtual void parse(std::vector<char*> &params) = 0;

protected:

	/**
	 * Retorna o número do registrador solicitado.
	 *
	 * \param name nome do registrador.
	 * \return número do registrador
	 */
	bit8_t getRegisterNumber(const char *name);


};

}; // namespace
