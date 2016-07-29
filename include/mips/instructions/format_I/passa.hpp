/**
 * \file passa.hpp
 *
 * Declaração da instrução de PASSA.
 */
#pragma once

#include <mips/instructions/instruction_I.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de PASSA no processador.
 *
 * \author Matheus Nogueira
 */
class PassaInstruction : public InstructionI {

public:

	/**
	 * Constroi uma nova instrução.
	 */
	 PassaInstruction(bit8_t opcode,
                         Register *rs,
                         Register *rt,
						 Register *rd,
                         bit8_t shamt,
                         bit8_t funct)
	: InstructionI(opcode, rs, rt, rd, shamt, funct) {}

	/**
	 * Função que executa a operação de soma.
	 *
	 * \return resultado da operação
	 */
	bit16_t execute();

};

}; // namespace
