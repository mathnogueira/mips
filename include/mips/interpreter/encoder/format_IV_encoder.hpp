/**
 * \file format_IV_encoder.hpp
 *
 * Arquivo contendo o codificador de instruções do formato IV.
 */
#pragma once

#include <mips/interpreter/encoder/encoder.hpp>
#include <vector>

namespace MIPS {

/**
 * Codificador responsável por transformar uma instrução assembly em uma instrução
 * binária, seguindo o formato de instrução no formato IV.
 *
 * \author Matheus Nogueira
 */
class FormatIVEncoder : public Encoder {

public:

	FormatIVEncoder() {}

	/**
	 * Codifica uma instrução assembly do formato IV para uma instrução binária.
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
