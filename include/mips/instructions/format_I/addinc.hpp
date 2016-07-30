/**
 * \file addinc.hpp
 *
 * Declaração da instrução de ADDINC.
 */
#pragma once

#include <mips/instructions/instruction_I.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de ADDINC no processador.
 *
 * \author Felipe Dias
 */
class AddIncInstruction : public InstructionI {

public:

	/**
	 * Constroi uma nova instrução.
	 */
	 AddIncInstruction(bit8_t opcode,
                         Register *rs,
                         Register *rt,
                         bit8_t shamt,
                         bit8_t funct)
	: InstructionI(opcode, rs, rt, shamt, funct) {}

	/**
	 * Função que executa a operação de soma.
	 *
	 * \return resultado da operação
	 */
	bit16_t execute();

};

}; // namespace
