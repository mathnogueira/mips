/**
 * \file format_II_encoder.hpp
 *
 * Arquivo contendo o codificador de instruções do formato II.
 */
#pragma once

#include <mips/interpreter/encoder/encoder.hpp>
#include <vector>

namespace MIPS {

/**
 * Codificador responsável por transformar uma instrução assembly em uma instrução
 * binária, seguindo o formato de instrução no formato II.
 *
 * \author Matheus Nogueira
 */
class FormatIIEncoder : public Encoder {

public:

	FormatIIEncoder() {}

	/**
	 * Codifica uma instrução assembly do formato II para uma instrução binária.
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
	 * Opcode da instrução.
	 */
	bit16_t opcode;

	/**
	 * Registrador de destino.
	 */
	bit16_t rd;

	/**
	 * Offset da instrução.
	 */
	bit16_t offset;
};

} // namespace
