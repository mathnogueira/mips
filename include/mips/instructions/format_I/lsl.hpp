/**
 * \file lsl.hpp
 *
 * Declaração da instrução de LSL.
 */
#pragma once

#include <mips/instructions/instruction_I.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de LSL no processador.
 *
 * \author Felipe Dias
 */
class LslInstruction : public InstructionI {

public:

	/**
	 * Constroi uma nova instrução.
	 */
	 LslInstruction(bit8_t opcode,
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
