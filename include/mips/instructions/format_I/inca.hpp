/**
 * \file add.hpp
 *
 * Declaração da instrução de INCA.
 */
#pragma once

#include <mips/instructions/instruction_I.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de INCA no processador.
 *
 * \author Felipe Dias
 */
class IncaInstruction : public InstructionI {

public:

	/**
	 * Constroi uma nova instrução.
	 */
	 IncaInstruction(bit8_t opcode,
                         Register *rs,
                         Register *rt,
                         bit8_t shamt,
                         bit8_t funct)
	: InstructionI(opcode, rs, rt, shamt, funct) {}

	/**
	 * Função que executa a operação de incremento.
	 *
	 * \return resultado da operação
	 */
	bit16_t execute();

};

}; // namespace
