/**
 * \file encoder.hpp
 *
 * Arquivo contendo um codificador genérico para instruções MIPS 32 bits.
 */
#pragma once

#include <mips/core.hpp>
#include <mips/interpreter/label.hpp>
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
	Encoder(std::vector<Label>& labels, const char *type);

	/**
	 * Destroi o codificador.
	 */
	virtual ~Encoder() {}

	/**
	 * Codifica uma instrução escrita em ASCII para uma instrução de 32 bits.
	 *
	 * \param params parametros da instrução.s
	 * \return instrução 32 bits.
	 */
	virtual instruction32_t encode(std::vector<char*>& params) = 0;

	/**
	 * Retorna o tipo de codificador.
	 *
	 * \return tipo de codificador.
	 */
	const char* getType();

protected:

	/**
	 * Lista de labels extraídos do código.
	 */
	std::vector<Label>& mLabels;

	/**
	 * Tipo de codificador (utilizado para verificação nos testes de unidade.)
	 */
	const char* mType;

};

}; // namespace
