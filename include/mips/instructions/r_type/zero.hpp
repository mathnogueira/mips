/**
 * \file zero.hpp
 *
 * Declaração da instrução de ZERO.
 */
#pragma once

#include <mips/instructions/register_instruction.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de ZERO no processador.
 *
 * \author Felipe Dias
 */
class ZeroInstruction : public RegisterInstruction {

public:

	/**
	 * Constroi uma nova instrução.
	 */
	 ZeroInstruction(bit8_t opcode,
                         Register *rs,
                         Register *rt,
						 Register *rd,
                         bit8_t shamt,
                         bit8_t funct)
	: RegisterInstruction(opcode, rs, rt, rd, shamt, funct) {}

	/**
	 * Função que executa a operação de soma.
	 */
	void execute();

};

}; // namespace
