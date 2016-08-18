/**
 * \file jal.hpp
 *
 * Instrução que realiza chamadas a procedimentos guardando o endereço do 
 * PC atual no registrador.
 */
#pragma once

#include <mips/instructions/instruction_VI.hpp>

namespace MIPS {

/**
 * Instrução que realiza chamadas a procedimentos guardando o endereço do 
 * PC atual no registrador.
 * 
 * \author Felipe Dias
 */
class JalInstruction : public InstructionVI {

public:
    
    /**
     * Cria uma nova instrução de Jump and Link
     *
     * \param opcode código da operação
     * \param rs registrador source
     * \param rt registrador target
     * \param pc registrador de contador de programa
     */
    JalInstruction(bit8_t opcode, Register *rs, Register *rt, Register *pc) :
		InstructionVI(opcode, rs, rt, pc) {}

    /**
     * Executa a instrução.
     *
     * \return returna 0 se o desvio não for tomado, 1 se desvio for tomado.
     */
     bit16_t execute();

};

} // namespace
