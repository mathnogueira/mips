/**
 * \file format_III_encoder.hpp
 *
 * Arquivo contendo o codificador de instruções do formato III.
 */
#pragma once

#include <mips/interpreter/encoder/encoder.hpp>
#include <vector>

namespace MIPS {

/**
 * Codificador responsável por transformar uma instrução assembly em uma instrução
 * binária, seguindo o formato de instrução no formato III.
 *
 * \author Matheus Nogueira
 */
class FormatIIIEncoder : public Encoder {

public:

	FormatIIIEncoder() {}

	/**
	 * Codifica uma instrução assembly do formato III para uma instrução binária.
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
	 * Registrador de destino.
	 */
	bit8_t rd;

	/**
	 * Bit de identificação da instrução.
	 */
	bit8_t r;

	/**
	 * Offset da instrução.
	 */
	bit16_t offset;

};

} // namespace
