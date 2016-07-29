/**
 * \file ones.hpp
 *
 * Declaração da instrução de ONES.
 */
#pragma once

#include <mips/instructions/instruction_I.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de ONES no processador.
 *
 * \author Felipe Dias
 */
class OnesInstruction : public InstructionI {

public:

	/**
	 * Constroi uma nova instrução.
	 */
	 OnesInstruction(bit8_t opcode,
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
