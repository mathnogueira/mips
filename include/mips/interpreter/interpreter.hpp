/**
 * \file interpreter.hpp
 *
 * Arquivo contendo a declaração do interpretador de instruções MIPS 32.
 */
#pragma once

#include <mips/core.hpp>
#include <mips/util/file_reader.hpp>

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
	 * Destroi o interpretador.
	 */
	~Interpreter();

	/**
	 * Inicia o processo de interpretação do arquivo.
	 *
	 * \return status da interpretação, retorna verdadeiro se tudo ocorreu corretamente.
	 */
	bool process();

private:

	/**
	 * Leitor de arquivos utilizado pelo interpretador.
	 */
	FileReader *fileReader;

};

}; // namespace
