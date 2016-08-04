/**
 * \file instruction_V.hpp
 *
 * Arquivo descrevendo o formato de uma instrução do formato V.
 */
#pragma once

#include <mips/core.hpp>
#include <mips/flag.hpp>
#include <mips/instructions/instruction.hpp>
#include <mips/memory/register.hpp>

namespace MIPS {

/**
 * Classe que representa uma instrução do formato V do trabalho.
 *
 * \author Matheus Nogueira
 */
class InstructionV : public Instruction {

public:

	/**
	 * Cria uma nova instrução do formato V
	 *
	 * \param opcode código da operação
     * \param offset offset do jump.
	 */
	InstructionV(bit8_t opcode, bit16_t offset) {
		this->opcode = opcode;
		this->offset = offset;
	}

	/**
	 * Executa a instrução.
	 *
	 * \return endereço da próxima instrução.
	 */
	virtual bit16_t execute() = 0;

protected:

	/**
	 * Offset do jump
	 */
	bit16_t offset;

};

} // namespace
