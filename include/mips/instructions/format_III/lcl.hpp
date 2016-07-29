/**
 * \file lhl.hpp
 *
 * Instrução que carrega  uma constante com sinal no bit menos significativo
 * do registrador.
 */
#pragma once

#include <mips/instructions/instruction_III.hpp>

namespace MIPS {

/**
 * Instrução utilizada para carregar 8 bits e carregá-los em um no bit menos
 * significativo do registrador definido pelo programador.
 *
 * \author Matheus Nogueira
 */
class LclInstruction : public InstructionIII {

public:

	/**
	 * Cria uma instrução de lhc.
	 *
	 * \param opcode código da operação
	 * \param rd registrador de destino
	 * \param offset offset de 11 bits
	 */
	LclInstruction(bit8_t opcode, Register *rd, bit8_t offset) :
		InstructionIII(opcode, rd, offset) {}

	/**
	 * Executa a instrução.
	 *
	 * \return resultado da operação
	 */
	bit16_t execute();

};

} // namespace
