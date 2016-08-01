/**
 * \file subdec.hpp
 *
 * Declaração da instrução de SubDec.
 */
#pragma once

#include <mips/instructions/instruction_I.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de subdec no processador.
 *
 * \author Lucas Pereira
 */
class SubdecInstruction : public InstructionI {

public:

    /**
	 * Constroi uma nova instrução.
	 */
	 SubdecInstruction(bit8_t opcode,
                         Register *rs,
                         Register *rt,
                         bit8_t shamt,
                         bit8_t funct)
	: InstructionI(opcode, rs, rt,  shamt, funct) {}


	/**
	 * Função que executa a operação de subtração.
	 */
	bit16_t execute();

};

}; // namespace
