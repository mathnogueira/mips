/**
 * \file instruction.hpp
 *
 * Arquivo contendo a estrutura abstrata que representa uma instrução qualquer
 * em uma arquitetura de 16 bits.
 *
 */
#pragma once

#include <mips/core.hpp>
#include <mips/units/control.hpp>
#include <mips/flag.hpp>

namespace MIPS {

/**
 * Classe abstrata responsável por representar qualquer instrução em uma
 * arquitetura de 16 bits.
 *
 * \author Matheus Nogueira
 */
class Instruction {

public:

    /**
     * Destroi a instrução.
     */
    ~Instruction() {}

    /**
     * Método abstrato que deverá ser invocado para que uma instrução seja
     * executada pelo emulador.
	 *
	 * \return resultado de saída da instrução.
     */
    virtual bit16_t execute() = 0;

    /**
     * Método utilizado para atualizar os sinais de controle do processador.
     *
     * \param control unidade de controle do processador.
     */
    virtual void updateControl(ControlUnit &control) {}

	/**
	 * Define a estrutura de flags da ALU.
	 *
	 * \param aluFlags flags da ALU.
	 */
	void setALUFlags(struct ALUFlags &aluFlags) {
		flags = &aluFlags;
	}

protected:

    /**
     * Código da operação (opcode) da instrução.
     */
    bit8_t opcode;

	/**
	 * Flags da ALU.
	 */
	struct ALUFlags *flags;
};

}; // namespace
