/**
 * \file format_I_encoder.hpp
 *
 * Arquivo contendo o codificador de instruções do formato I.
 */
#pragma once

#include <mips/core.hpp>
#include <mips/interpreter/encoder/encoder.hpp>
#include <vector>

namespace MIPS {

/**
 * Codificador responsável por transformar uma instrução assembly em uma instrução
 * binária, seguindo o formato de instrução no formato I.
 *
 * \author Matheus Nogueira
 */
class FormatIEncoder : public Encoder {

public:

	FormatIEncoder() {}

	/**
	 * Codifica uma instrução assembly do formato I para uma instrução binária.
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
	 * Número do registrador Rs.
	 */
	bit8_t rs;

	/**
	 * Número do registrador Rt.
	 */
	bit8_t rt;

	/**
	 * Número do registrador Rd.
	 */
	bit8_t rd;

	/**
	 * Código de função da operaçao.
	 */
	bit8_t funct;

};

} // namespace
