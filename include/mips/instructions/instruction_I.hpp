/**
 * \file instruction_I.hpp
 *
 * Arquivo contendo uma classe que representa uma instrução do tipo (R)egister.
 */
#pragma once

#include <mips/core.hpp>
#include <mips/instructions/instruction.hpp>
#include <mips/memory/register.hpp>

namespace MIPS {

/**
 * Classe que representa uma instrução do tipo (R)egister.
 *
 * \author Matheus Nogueira
 */
class InstructionI : public Instruction {

public:

    /**
     * Cria uma nova instrução do formato I.
     *
     * \param opcode codigo da operação
     * \param rs registrador source
     * \param rt registrador target
     * \param rd registrador destination
     * \param shamt quantidade de shift
     * \param funct bits para escolha da função da instrução
     */
    InstructionI(bit8_t opcode,
                        Register *rs,
                        Register *rt,
						Register *rd,
                        bit8_t shamt,
                        bit8_t funct) {
		this->opcode = opcode;
		this->rs = rs;
		this->rd = rd;
		this->rt = rt;
		this->shamt = shamt;
		this->funct = funct;
	}

    /**
     * Destroi a instrução.
     */
     virtual ~InstructionI() {}

	 /**
	  * Executa a instrução
	  */
	 virtual void execute() = 0;

protected:

    /**
     * Registrador source (Rs) da instrução.
     */
    Register *rs;

    /**
     * Registrador target (Rt) da instrução.
     */
    Register *rt;

    /**
     * Registrador destination (Rd) da instrução.
     */
    Register *rd;

    /**
     * Valor do shamt (shift amount) da instrução.
     */
    bit8_t shamt;

    /**
     * Valor da funct da instrução.
     */
    bit8_t funct;

};

}; // namespace