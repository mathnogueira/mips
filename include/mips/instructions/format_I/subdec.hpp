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
	 * Função que executa a operação de subtração.
	 */
	void execute();

};

}; // namespace
