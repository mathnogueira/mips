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
