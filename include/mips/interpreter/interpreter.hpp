/**
 * \file interpreter.hpp
 *
 * Arquivo contendo a declaração do interpretador de instruções MIPS 32.
 */
#pragma once

#include <mips/core.hpp>

namespace MIPS {

/**
 * Classe responsável por receber um texto e criar instruções 32 bits correspondentes
 * para a arquitetura MIPS 32.
 *
 * \author Matheus Nogueira
 */
class Interpreter {

public:

	/**
	 * Cria uma nova instância do interpretador.
	 *
	 * \param file arquivo que será interpretado.
	 */
	Interpreter(const char* file);

	/**
	 * Inicia o processo de interpretação do arquivo.
	 *
	 * \return status da interpretação, retorna verdadeiro se tudo ocorreu corretamente.
	 */
	bool process();

private:

	/**
	 * Nome do arquivo que será interpretado.
	 */
	const char* file;

};

}; // namespace
