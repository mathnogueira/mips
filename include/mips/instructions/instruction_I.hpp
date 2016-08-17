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
     * \param shamt quantidade de shift
     * \param funct bits para escolha da função da instrução
     */
    InstructionI(bit8_t opcode,
                        Register *rs,
                        Register *rt,
                        bit8_t shamt,
                        bit8_t funct) {
		this->opcode = opcode;
		this->rs = rs;
		this->rt = rt;
		this->shamt = shamt;
		this->funct = funct;
	}

    /**
     * Destroi a instrução.
     */
     virtual ~InstructionI() {}

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
     * Registrador source (Rs) da instrução.
     */
    Register *rs;

    /**
     * Registrador target (Rt) da instrução.
     */
    Register *rt;

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
