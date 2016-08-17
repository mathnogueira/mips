/**
 * \file instruction_III.hpp
 *
 * Arquivo descrevendo o formato de uma instrução do formato III.
 */
#pragma once

#include <mips/core.hpp>
#include <mips/instructions/instruction.hpp>
#include <mips/memory/register.hpp>

namespace MIPS {

/**
 * Classe que representa uma instrução do formato III do trabalho.
 *
 * \author Matheus Nogueira
 */
class InstructionIII : public Instruction {

public:

	/**
	 * Cria uma nova instrução do formato III
	 *
	 * \param opcode código da operação
	 * \param rd registrador de destino
	 * \param offset offset de 8 bits
	 */
	InstructionIII(bit8_t opcode, Register *rd, bit8_t offset) {
		this->opcode = opcode;
		this->rd = rd;
		this->offset = offset;
	}

	/**
	 * Executa a instrução.
	 *
	 * \return resultado da instrução
	 */
	virtual bit16_t execute() = 0;

	/**
	 * Método utilizado para atualizar os sinais de controle do processador.
	 *
	 * \param control unidade de controle do processador.
	 */
	void updateControl(ControlUnit &control) {
		control.regwrite = true;
		control.regDst = true; // RD
	}

protected:

	/**
	 * Registrador de destino da instrução.
	 */
	Register *rd;

	/**
	 * Offset utilizado pela instrução.
	 */
	bit8_t offset;

};

} // namespace
