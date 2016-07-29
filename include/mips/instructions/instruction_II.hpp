/**
 * \file instruction_II.hpp
 *
 * Arquivo descrevendo o formato de uma instrução do formato II.
 */
#pragma once

#include <mips/core.hpp>
#include <mips/instructions/instruction.hpp>
#include <mips/memory/register.hpp>

namespace MIPS {

/**
 * Classe que representa uma instrução do formato II do trabalho.
 *
 * \author Matheus Nogueira
 */
class InstructionII : public Instruction {

public:

	/**
	 * Cria uma nova instrução do formato II
	 *
	 * \param opcode código da operação
	 * \param rd registrador de destino
	 * \param offset offset de 11 bits.
	 */
	InstructionII(bit8_t opcode, Register *rd, bit16_t offset) {
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

protected:

	/**
	 * Registrador de destino da instrução.
	 */
	Register *rd;

	/**
	 * Offset utilizado pela instrução.
	 */
	bit16_t offset;

};

} // namespace
