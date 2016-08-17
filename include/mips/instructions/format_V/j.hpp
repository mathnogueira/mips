/**
 * \file j.hpp
 *
 * Instrução que faz o desvio incondicional.
 */
#pragma once

#include <mips/instructions/instruction_V.hpp>

namespace MIPS {

/**
 * Instrução que faz o desvio se a flag zero da ALU está setada como 1.
 *
 * \author Matheus Nogueira
 */
class JumpInstruction : public InstructionV {

public:

	/**
	 * Cria uma instrução de jump.
	 *
	 * \param opcode código da operação
	 * \param offset offset de 12 bits
	 */
	JumpInstruction(bit8_t opcode, bit16_t offset) :
		InstructionV(opcode, offset) {}

	/**
     * Método utilizado para atualizar os sinais de controle do processador.
     *
     * \param control unidade de controle do processador.
     */
    void updateControl(ControlUnit &control);

	/**
	 * Executa a instrução.
	 *
	 * \return returna 0 se o desvio não for tomado, 1 se desvio for tomado.
	 */
	 bit16_t execute();

};

} // namespace
