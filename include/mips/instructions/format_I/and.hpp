/**
 * \file and.hpp
 *
 * Declaração da instrução de andnota.
 */
#pragma once

#include <mips/instructions/instruction_I.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de and no processador.
 *
 * \author Lucas Fonseca dos Santos
 */
class AndInstruction : public InstructionI {

public:

	/**
	 * Constroi uma nova instrução.
	 */
	 AndInstruction(bit8_t opcode,
                         Register *rs,
                         Register *rt,
                         bit8_t shamt,
                         bit8_t funct)
	: InstructionI(opcode, rs, rt, shamt, funct) {}

	/**
	 * Função que executa a operação de AndInstruction.
	 */
	bit16_t execute();

};

}; // namespace
