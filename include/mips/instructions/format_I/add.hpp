/**
 * \file add.hpp
 *
 * Declaração da instrução de ADD.
 */
#pragma once

#include <mips/instructions/instruction_I.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de ADD no processador.
 *
 * \author Debora Rossini
 */
class AddInstruction : public InstructionI {

public:
	/**
	 * Função que executa a operação de soma.
	 *
	 * \return resultado da soma
	 */
	bit16_t execute();

};

}; // namespace
