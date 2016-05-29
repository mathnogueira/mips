/**
 * \file i_encoder.hpp
 *
 * Arquivo contendo um condificador de instruções do tipo R.
 */
#pragma once

#include <mips/interpreter/encoder/encoder.hpp>

namespace MIPS {

/**
 * Codificador de instruções do tipo I.
 *
 * \author Matheus Nogueira
 */
class REncoder : public Encoder {

public:

	/**
	 * Cria um novo codificador de instruções do tipo R.
	 *
 	 * \param labels tabela de labels extraídos do código.
 	 */
 	REncoder(std::vector<Label>& labels) : Encoder(labels, "R") {}

	/**
	 * Codifica uma instrução assembly para uma instrução de 32 bits.
	 *
	 * \param params paramêtros da instrução assembly.
	 * \return instrução 32 bits.
	 */
	instruction32_t encode(std::vector<char*>& params);

};

}; // namespace
