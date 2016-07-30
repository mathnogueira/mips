/**
 * \file add.hpp
 *
 * Declaração da instrução de ADD.
 */
#pragma once

#include <mips/instructions/instruction_I.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de ADD no processador.
 *
 * \author Felipe Dias
 */
class AddInstruction : public InstructionI {

public:

	/**
	 * Constroi uma nova instrução.
	 */
	 AddInstruction(bit8_t opcode,
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
