/**
 * \file xnor.hpp
 *
 * Declaração da instrução de XNOR.
 */
#pragma once

#include <mips/instructions/instruction_I.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de XNOR no processador.
 *
 * \author Matheus Nogueira
 */
class XnorInstruction : public InstructionI {

public:

	/**
	 * Constroi uma nova instrução.
	 */
	 XnorInstruction(bit8_t opcode,
                         Register *rs,
                         Register *rt,
						 Register *rd,
                         bit8_t shamt,
                         bit8_t funct)
	: InstructionI(opcode, rs, rt, rd, shamt, funct) {}

	/**
	 * Função que executa a operação de soma.
	 */
	void execute();

};

}; // namespace