/**
 * \file filter.hpp
 *
 * Arquivo contendo um filtro de string abstrato.
 */
#pragma once

#include <string>

namespace MIPS {

/**
 * Classe abstrata que representa um filtro de texto.
 *
 * \author Matheus Nogueira
 */
class Filter {

public:

	/**
	 * Filtra uma string e retorna uma nova instância da mesma.
	 *
	 * \param input string a ser filtrada.
	 * \return string filtrada.
	 */
	virtual std::string filter(std::string& input) = 0;

};

};
