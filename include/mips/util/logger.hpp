/**
 * \file logger.hpp
 */
#pragma once

#include <mips/memory/register_bank.hpp>
#include <mips/memory/memory.hpp>
#include <mips/flag.hpp>

namespace MIPS {

/**
 * Classe responsável por realizar o log de execução do processador.
 *
 * \author Matheus Nogueira
 */
class Logger {

public:

	/**
	 * Imprime o estado do processador.
	 *
	 * \param bank banco de registradores
	 * \param flags flags da ALU
	 * \param instruction instrução executada
	 */
	void static screen(RegisterBank &bank, struct ALUFlags flags, instruction_t instruction);

	/**
	 * Imprime a memória do processador.
	 *
	 * \param memory memória do processador.
	 * \param start inicio do dump
	 * \param size número de palavras que serão exibidas.
	 */
	void static dump(Memory &memory, bit16_t start, bit16_t size);

};


} // namespace
