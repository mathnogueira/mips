/**
 * \file load.hpp
 *
 * Instrução de Load, carrega no registrador C o conteúdo da memória
 * endereçada pelo registrador A.
 */
#pragma once

#include <mips/instructions/instruction_VII.hpp>

namespace MIPS {

/**
 * Instrução de Load, carrega no registrador C o conteúdo da memória
 * endereçada pelo registrador A.
 *
 * \author Felipe Dias
 */
class LoadInstruction : public InstructionVII {

public:
	/**
	 * Constroi uma nova instrução.
	 */
	 LoadInstruction(bit8_t opcode,
                         Register *rs,
                         Register *rt,
                         Memory *memory)
	: InstructionVII(opcode, rs, rt, memory) {}


	/**
	 * Executa a instrução.
	 *
	 * \return resultado da instrução
	 */
	bit16_t execute();

	/**
	 * Método utilizado para atualizar os sinais de controle do processador.
	 *
	 * \param control unidade de controle do processador.
	 */
	void updateControl(ControlUnit &control) {
		control.regwrite = true;
		control.regDst = false; // RD
		control.memRead = true;
	}

};

} // namespace
