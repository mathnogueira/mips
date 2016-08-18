/**
 * \file lch.hpp
 *
 * Instrução que faz o desvio quando a flag zero da alu é igual a 1.
 */
#pragma once

#include <mips/instructions/instruction_IV.hpp>

namespace MIPS {

/**
 * Instrução que faz o desvio se a flag zero da ALU está setada como 1.
 *
 * \author Matheus Nogueira
 */
class JtZeroInstruction : public InstructionIV {

public:

    /**
     * Cria uma instrução de jump on true.
     *
     * \param opcode código da operação
     * \param aluFlags objeto de flags da ALU
    * \param offset offset de 8 bits
    */
   JtZeroInstruction(bit8_t opcode, struct ALUFlags &aluFlags, bit8_t offset) :
           InstructionIV(opcode, aluFlags, offset) {}

   /**
    * Executa a instrução.
    *
    * \return retorna 0 se o desvio não for tomado, 1 se desvio for tomado.
    */
   bit16_t execute();

};

} // namespace
