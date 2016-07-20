/**
 * \file add.hpp
 *
 * Declaração da instrução de ADD.
 */
#pragma once

#include <mips/instructions/register_instruction.hpp>

namespace MIPS {

/**
 * Classe que faz a operação de ADD no processador.
 *
 * \author Debora Rossini
 */
class AddInstruction : public RegisterInstruction {

public:
	/**
	 * Função que executa a operação de soma.
	 */
	void execute();

};

}; // namespace
