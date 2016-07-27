/**
 * \file i_encoder.hpp
 *
 * Arquivo contendo um condificador de instruções do tipo J.
 */
#pragma once

#include <mips/interpreter/encoder/encoder.hpp>
#include <mips/core.hpp>

namespace MIPS {

/**
 * Codificador de instruções do tipo J.
 *
 * \author Matheus Nogueira
 */
class JEncoder : public Encoder {

public:

	/**
	 * Cria um novo codificador de instruções do tipo J.
	 *
 	 * \param labels tabela de labels extraídos do código.
 	 */
 	JEncoder(std::vector<Label>& labels) : Encoder(labels, "J") {}

	/**
	 * Codifica uma instrução assembly para uma instrução de 32 bits.
	 *
	 * \return instrução 32 bits.
	 */
	instruction_t encode();


protected:

	/**
	 * Opcode da instrução.
	 */
	bit8_t opcode;

	/**
	 * Pseudo-endereço para onde o contador de programa deve ser transferido.
	 */
	bit32_t address;

};

}; // namespace
