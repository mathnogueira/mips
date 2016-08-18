/**
 * \file lsr.hpp
 *
 * Declaração da instrução de LSR.
 */
#pragma once

#include <mips/instructions/instruction_I.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de LSR no processador.
 *
 * \author Felipe Dias
 */
class LsrInstruction : public InstructionI {

public:

	/**
	 * Constroi uma nova instrução.
	 */
	 LsrInstruction(bit8_t opcode,
                         Register *rs,
                         Register *rt,
                         bit8_t shamt,
                         bit8_t funct)
	: InstructionI(opcode, rs, rt, shamt, funct) {}

	/**
	 * Função que executa a operação de decremento.
	 *
	 * \return resultado da operação
	 */
	bit16_t execute();

};

}; // namespace
