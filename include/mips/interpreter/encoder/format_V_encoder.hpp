/**
 * \file format_V_encoder.hpp
 *
 * Arquivo contendo o codificador de instruções do formato V.
 */
#pragma once

#include <mips/interpreter/encoder/encoder.hpp>
#include <vector>

namespace MIPS {

/**
 * Codificador responsável por transformar uma instrução assembly em uma instrução
 * binária, seguindo o formato de instrução no formato V.
 *
 * \author Matheus Nogueira
 */
class FormatVEncoder : public Encoder {

public:

	FormatVEncoder() {}

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

};

} // namespace
