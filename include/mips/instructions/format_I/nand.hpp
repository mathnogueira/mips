/**
 * \file nand.hpp
 *
 * Declaração da instrução de NAND.
 */
#pragma once

#include <mips/instructions/instruction_I.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de NAND no processador.
 *
 * \author Matheus Nogueira
 */
class NandInstruction : public InstructionI {

public:

	/**
	 * Constroi uma nova instrução.
	 */
	 NandInstruction(bit8_t opcode,
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