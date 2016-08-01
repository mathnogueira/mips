/**
 * \file add.hpp
 *
 * Declaração da instrução de DECA.
 */
#pragma once

#include <mips/instructions/instruction_I.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de DECA no processador.
 *
 * \author Felipe Dias
 */
class DecaInstruction : public InstructionI {

public:

	/**
	 * Constroi uma nova instrução.
	 */
	 DecaInstruction(bit8_t opcode,
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
