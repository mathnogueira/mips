/**
 * \file instruction_IV.hpp
 *
 * Arquivo descrevendo o formato de uma instrução do formato IV.
 */
#pragma once

#include <mips/core.hpp>
#include <mips/flag.hpp>
#include <mips/instructions/instruction.hpp>
#include <mips/memory/register.hpp>

namespace MIPS {

/**
 * Classe que representa uma instrução do formato IV do trabalho.
 *
 * \author Matheus Nogueira
 */
class InstructionIV : public Instruction {

public:

	/**
	 * Cria uma nova instrução do formato IV
	 *
	 * \param opcode código da operação
	 * \param aluFlags Flags vindas da ALU
     * \param offset offset do jump.
	 */
	InstructionIV(bit8_t opcode, struct ALUFlags &aluFlags, bit8_t offset) :  flags(aluFlags) {
		this->opcode = opcode;
		this->offset = offset;
	}

	/**
	 * Executa a instrução.
	 *
	 * \return 0 se o desvio não é tomado, 1 se o desvio for tomado.
	 */
	virtual bit16_t execute() = 0;

	/**
	 * Método utilizado para atualizar os sinais de controle do processador.
	 *
	 * \param control unidade de controle do processador.
	 */
	void updateControl(ControlUnit &control) {
		control.branch = true;
	}

protected:

	/**
	 * Offset da instrução de jump
	 */
	bit8_t offset;

	/**
	 * Flags de saída da ALU
	 */
	struct ALUFlags &flags;

};

} // namespace
