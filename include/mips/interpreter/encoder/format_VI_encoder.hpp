/**
 * \file format_VI_encoder.hpp
 *
 * Arquivo contendo o codificador de instruções do formato VI.
 */
#pragma once

#include <mips/interpreter/encoder/encoder.hpp>
#include <vector>

namespace MIPS {

/**
 * Codificador responsável por transformar uma instrução assembly em uma instrução
 * binária, seguindo o formato de instrução no formato VI.
 *
 * \author Matheus Nogueira
 */
class FormatVIEncoder : public Encoder {

public:

	FormatVIEncoder() {}

	/**
	 * Codifica uma instrução assembly do formato V para uma instrução binária.
	 *
	 * \return instrução binária de 16 bits
	 */
	instruction_t encode();

	/**
	 * Realiza uma varredura na instrução assembly e define seus campos binários.
	 *
	 * \param params vector de parâmetros da instrução
	 */
	void parse(std::vector<char*> &params);

private:

	/**
	 * Código de função da operação.
	 */
	bit8_t funct;

	/**
	 * Bit de seleção de operação.
	 */
	bit8_t r;

	/**
	 * Registrador target.
	 */
	bit8_t rt;

};

} // namespace
