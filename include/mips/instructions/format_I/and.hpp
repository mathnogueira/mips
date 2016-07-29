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
						 					 	 Register *rd,
                         bit8_t shamt,
                         bit8_t funct)
	: InstructionI(opcode, rs, rt, rd, shamt, funct) {}

	/**
	 * Função que executa a operação de AndInstruction.
	 */
	void execute();

};

}; // namespace
