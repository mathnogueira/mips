/**
 * \file interpreter.hpp
 *
 * Arquivo contendo a declaração do interpretador de instruções MIPS 32.
 */
#pragma once

#include <mips/core.hpp>
#include <mips/interpreter/label.hpp>
#include <mips/util/file_reader.hpp>
#include <iostream>

namespace MIPS {

/**
 * Classe responsável por receber um texto e criar instruções 16 bits correspondentes
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
	 * Processa o arquivo de entrada para que ele possa ser interpretado.
	 *
	 * \param output arquivo que será escrito com as instruções.
	 */
	void compile(const char *output = "out.mips");

	/**
	 * Checa se o interpretador encontrou algum erro durante a sua execução. Se sim,
	 * retorna false.
	 *
	 * \return true se o interpretador realizou sem papel sem erros.
	 */
	bool ok() {
		return (bool) (errors == 0);
	}

private:

	/**
	 * Leitor de arquivos utilizado pelo interpretador.
	 */
	FileReader *fileReader;

	/**
	 * Buffer de tokens extraídos do arquivo fonte.
	 */
	std::vector<std::vector<char*> > lines;

	/**
	 * Labels encontrados no codigo.
	 */
	std::vector<Label> labels;

	/**
	 * Numero de erros que ocorreram durante o processo de interpretação.
	 */
	bit16_t errors;

	/**
	 * Identifica todos os labels presentes no código e os marcam para ser utilizados
	 * futuramente.
	 */
	void extractLabels();

	/**
	 * Remove todos os labels do código e os troca pela posição relativa do label.
	 */
	void updateLabels();

	/**
	 * Codifica as linhas do programa para que o emulador possa utilizá-las
	 * em seu datapath.
	 *
	 * \param fp arquivo onde o código compilado será colocado.
	 */
	void encode(FILE *fp);

};

}; // namespace
