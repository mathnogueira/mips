/**
 * \file nand.hpp
 *
 * Declaração da instrução de NAND.
 */
#pragma once

#include <mips/instructions/register_instruction.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de ADD no processador.
 *
 * \author Debora Rossini
 */
class NandInstruction : public RegisterInstruction {

public:

	/**
	 * Constroi uma nova instrução.
	 */
	 NandInstruction(bit8_t opcode,
                         Register *rs,
                         Register *rd,
                         Register *rt,
                         bit8_t shamt,
                         bit8_t funct)
	: RegisterInstruction(opcode, rs, rd, rt, shamt, funct) {}

	/**
	 * Função que executa a operação de soma.
	 */
	void execute();

};

}; // namespace
