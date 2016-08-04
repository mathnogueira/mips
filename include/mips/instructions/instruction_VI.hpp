/**
 * \file instruction_VI.hpp
 *
 * Arquivo descrevendo o formato de uma instrução do formato VI.
 */
#pragma once

#include <mips/core.hpp>
#include <mips/flag.hpp>
#include <mips/instructions/instruction.hpp>
#include <mips/memory/register.hpp>

namespace MIPS {

/**
 * Classe que representa uma instrução do formato VI do trabalho.
 *
 * \author Matheus Nogueira
 */
class InstructionVI : public Instruction {

public:

	/**
	 * Cria uma nova instrução do formato VI
	 *
	 * \param opcode código da operação
	 * \param rt registrador target
     * \param pc registrador de contador de programa
	 */
	InstructionVI(bit8_t opcode, Register *rt, Register *pc) {
		this->opcode = opcode;
        this->rt = rt;
        this->pc = pc;
	}

	/**
	 * Executa a instrução.
	 *
	 * \return resultado da instrução
	 */
	virtual bit16_t execute() = 0;

protected:

	/**
	 * Registrador de contador de programa
	 */
	Register *pc;

    /**
     * Registrador target.
     */
    Register *rt;

};

} // namespace
