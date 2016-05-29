/**
 * \file interpreter.hpp
 *
 * Arquivo contendo a declaração do interpretador de instruções MIPS 32.
 */
#pragma once

#include <mips/core.hpp>
#include <mips/interpreter/label.hpp>
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
	 */
	void process();

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
	 * Atualiza os labels para que eles virem o numero da linha
	 * do inicio do bloco do label.
	 */
	void updateLabels();

	/**
	 * Processa todas as linhas de assembly e as transforma em instruções
	 * 32 bits.
	 */
	void convertToInstructions();

};

}; // namespace
