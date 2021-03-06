/**
 * \file andnota.hpp
 *
 * Declaração da instrução de andnota.
 */
#pragma once

#include <mips/instructions/instruction_I.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de andnota no processador.
 *
 * \author Lucas Pereira
 */
class AndnotaInstruction : public InstructionI {

public:

	/**
	 * Constroi uma nova instrução.
	 */
	 AndnotaInstruction(bit8_t opcode,
                         Register *rs,
                         Register *rt,
                         bit8_t shamt,
                         bit8_t funct)
	: InstructionI(opcode, rs, rt, shamt, funct) {}

	/**
	 * Função que executa a operação de AndnotaInstruction.
	 *
	 * \return resultado da operação
	 */
	bit16_t execute();

};

}; // namespace
