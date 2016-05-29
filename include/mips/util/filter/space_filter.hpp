/**
 * \file space_filter.hpp
 *
 * Arquivo contendo um filtro que retira tabulações e espaços em branco
 * desnecessários de um texto.
 *
 */
#pragma once

#include <mips/util/filter/filter.hpp>

namespace MIPS {

/**
 * Classe responsável por remover espaços e tabulações de um texto.
 *
 * \author Matheus Matheus Nogueira
 */
class SpaceFilter : public Filter {

public:
	/**
	 * Remove todos os espaços e tabulações de uma string.
	 *
	 * \param input string a ser filtrada.
	 * \return string filtrada.
	 */
	std::string filter(std::string& input);

private:

	/**
	 * Remove tabs de uma string.
	 */
	std::string removeTabs(std::string& input);

	/**
	 * Remove espaços antes e depois da linha.
	 */
	std::string trim(std::string& input);
};

};
