/**
 * \file jt_neg.hpp
 *
 * Instrução que faz o desvio quando a flag neg da alu é igual a 1.
 */
#pragma once

#include <mips/instructions/instruction_IV.hpp>

namespace MIPS {

/**
 * Instrução que faz o desvio quando a flag neg da alu é igual a 1.
 *
 * \author Felipe Dias
 */
class JtNegInstruction : public InstructionIV {

public:

    /**
     * Cria uma instrução de jump on true.
     *
     * \param opcode código da operação
     * \param aluFlags objeto de flags da ALU
     * \param offset offset de 8 bits
     */
    JtNegInstruction(bit8_t opcode, struct ALUFlags &aluFlags, bit8_t offset) :
            InstructionIV(opcode, aluFlags, offset) {}

    /**
     * Executa a instrução.
     *
     * \return returna 0 se o desvio não for tomado, 1 se desvio for tomado.
     */
    bit16_t execute();

};

} // namespace
