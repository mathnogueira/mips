/**
 * \file jt_carry.hpp
 *
 * Instrução que faz o desvio quando a flag carry da alu é igual a 0.
 */
#pragma once

#include <mips/instructions/instruction_IV.hpp>

namespace MIPS {

/**
 * Instrução que faz o desvio se a flag carry da ALU está setada como 0.
 *
 * \author Felipe Dias
 */
class JtCarryInstruction : public InstructionIV {

public:

    /**
     * Cria uma instrução de jump on true.
     *
     * \param opcode código da operação
     * \param aluFlags objeto de flags da ALU
    * \param offset offset de 8 bits
    */
    JtCarryInstruction(bit8_t opcode, struct ALUFlags &aluFlags, bit8_t offset) :
            InstructionIV(opcode, aluFlags, offset) {}

    /**
     * Executa a instrução.
     *
     * \return retorna 1 se o desvio não for tomado, 0 se desvio for tomado.
     */
    bit16_t execute();

};

} // namespace
