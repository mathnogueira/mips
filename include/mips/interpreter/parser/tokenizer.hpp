/**
 * \file tokenizer.hpp
 *
 * Arquivo contendo a classe responsável por separar uma string em tokens.
 */
#pragma once

#include <vector>

namespace MIPS {

/**
 * Classe responsável por quebrar uma string em diversos tokens.
 *
 * \author Matheus Nogueira
 */
class Tokenizer {

public:

	/**
	 * Retira os tokens de uma string e os armazena em um vector.
	 *
	 * \param str string contendo os tokens
	 * \param vector vector que será usado para armazenar os tokens
	 */
	void tokenize(char *str, std::vector<char*> &vector);

};

}; // namespace
