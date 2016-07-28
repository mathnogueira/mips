/**
 * \file loadlit.hpp
 *
 * Instrução que carrega  uma constante com sinal em um registrador.
 */
#pragma once

#include <mips/instructions/instruction_II.hpp>

namespace MIPS {

/**
 * Instrução utilizada para carregar 11 bits e carregá-los em um registrador
 * definido pelo programador.
 *
 * \author Matheus Nogueira
 */
class LoadlitInstruction : public InstructionII {

public:

	/**
	 * Cria uma instrução de loadlit.
	 *
	 * \param opcode código da operação
	 * \param rd registrador de destino
	 * \param offset offset de 11 bits
	 */
	LoadlitInstruction(bit8_t opcode, Register *rd, bit16_t offset) :
		InstructionII(opcode, rd, offset) {}

	/**
	 * Executa a instrução.
	 */
	void execute();

};

} // namespace
