/**
 * \file or.hpp
 *
 * Declaração da instrução de or.
 */
#pragma once

#include <mips/instructions/instruction_I.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de OR no processador.
 *
 * \author Lucas Fonseca dos Santos
 */
class OrInstruction : public InstructionI {

public:

	/**
	 * Constroi uma nova instrução.
	 */
	 OrInstruction(bit8_t opcode,
                         Register *rs,
                         Register *rt,
                         bit8_t shamt,
                         bit8_t funct)
	: InstructionI(opcode, rs, rt, shamt, funct) {}

	/**
	 * Função que executa a operação de OrInstruction.
	 */
	bit16_t execute();

};

}; // namespace
