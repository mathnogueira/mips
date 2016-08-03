/**
 * \file lch.hpp
 *
 * Instrução que carrega  uma constante com sinal no bit mais significativo
 * do registrador.
 */
#pragma once

#include <mips/instructions/instruction_III.hpp>

namespace MIPS {

/**
 * Instrução utilizada para carregar 8 bits e carregá-los em um no bit mais
 * significativo do registrador definido pelo programador.
 *
 * \author Matheus Nogueira
 */
class LchInstruction : public InstructionIII {

public:

	/**
	 * Cria uma instrução de lhc.
	 *
	 * \param opcode código da operação
     * \param rd registrador rd
	 * \param offset offset de 11 bits
	 */
	LchInstruction(bit8_t opcode, Register *rd, bit8_t offset) :
		InstructionIII(opcode, rd, offset) {}

	/**
	 * Executa a instrução.
	 *
	 * \return resultado da operação
	 */
	bit16_t execute();

};

} // namespace
