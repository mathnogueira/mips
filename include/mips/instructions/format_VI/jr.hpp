/**
 * \file jr.hpp
 *
 * Armazena o conteúdo do registrador b em PC.
 */
#pragma once

#include <mips/instructions/instruction_VI.hpp>

namespace MIPS {

/**
 * Armazena o conteúdo do registrador b em PC.
 * 
 * \author Felipe Dias
 */
class JrInstruction : public InstructionVI {

public:
    
    /**
     * Cria uma nova instrução de Jump Register
     *
     * \param opcode código da operação
     * \param rs registrador source
     * \param rt registrador target
     * \param pc registrador de contador de programa
     */
    JrInstruction(bit8_t opcode, Register *rs, Register *rt, Register *pc) :
		InstructionVI(opcode, rs, rt, pc) {}

    /**
     * Executa a instrução.
     *
     * \return returna 0 se o desvio não for tomado, 1 se desvio for tomado.
     */
     bit16_t execute();

};

} // namespace
