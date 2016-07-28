/**
 * \file andnota.hpp
 *
 * Declaração da instrução de andnota.
 */
#pragma once

#include <mips/instructions/register_instruction.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de andnota no processador.
 *
 * \author Lucas Pereira
 */
class AndnotaInstruction : public RegisterInstruction {

public:

	/**
	 * Constroi uma nova instrução.
	 */
	 AndnotaInstruction(bit8_t opcode,
                         Register *rs,
                         Register *rt,
						 Register *rd,
                         bit8_t shamt,
                         bit8_t funct)
	: RegisterInstruction(opcode, rs, rt, rd, shamt, funct) {}

	/**
	 * Função que executa a operação de AndnotaInstruction.
	 */
	void execute();

};

}; // namespace
