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
	Encoder(std::vector<Label>& labels, const char *type);

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

	/**
	 * Estrutura que armazena o opcode da instrução e o seu código de função.
	 */
	struct InstructionInfo {
		const char *name;	///< Nome da instrução
		bit8_t opcode;		///< Opcode da instrução
		bit8_t funct;		///< Código da função
	};

	/**
	 * Retorna o número do registrador utilizando seu nome como identificador.
	 *
	 * \param name nome do registrador.
	 * \return número do registrador.
	 */
	bit8_t getRegisterNumber(char *name);

	/**
	 * Retorna o opcode da instrução e o código de função, se aplicável.
	 *
	 * \param name nome da instrução.
	 * \param info objeto onde o resultado será gravado.
	 */
	struct InstructionInfo getInstructionInfo(char *name);

private:

	/**
	 * Mapa que mapeia todos as instruções do mips.
	 */
	std::vector<struct InstructionInfo> map;

	/**
	 * Popula o mapa com os dados de todas as instruções.
	 */
	void initMap();
};

}; // namespace
