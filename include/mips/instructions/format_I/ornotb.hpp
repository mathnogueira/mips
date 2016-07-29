/**
 * \file ornotb.hpp
 *
 * Declaração da instrução de ornotb.
 */
#pragma once

#include <mips/instructions/instruction_I.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de ornotb no processador.
 *
 * \author Lucas Pereira
 */
class OrnotbInstruction : public InstructionI {

public:

	/**
	 * Constroi uma nova instrução.
	 */
	 OrnotbInstruction(bit8_t opcode,
                         Register *rs,
                         Register *rt,
						 Register *rd,
                         bit8_t shamt,
                         bit8_t funct)
	: InstructionI(opcode, rs, rt, rd, shamt, funct) {}

	/**
	 * Função que executa a operação de OrnotbInstruction.
	 */
	void execute();

};

}; // namespace
