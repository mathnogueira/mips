/**
 * \file jf_overflow.hpp
 *
 * Instrução que faz o desvio quando a flag overflow é igual a 0.
 */
#pragma once

#include <mips/instructions/instruction_IV.hpp>

namespace MIPS {

/**
 * Instrução que faz o desvio quando a flag overflow é igual a 0.
 *
 * \author Felipe Dias
 */
class JfOverflowInstruction : public InstructionIV {

public:

    /**
     * Cria uma instrução de jump on true.
     *
     * \param opcode código da operação
     * \param aluFlags objeto de flags da ALU
     * \param offset offset de 8 bits
     */
    JfOverflowInstruction(bit8_t opcode, struct ALUFlags &aluFlags, bit8_t offset) :
            InstructionIV(opcode, aluFlags, offset) {}

    /**
     * Executa a instrução.
     *
     * \return returna 0 se o desvio não for tomado, 1 se desvio for tomado.
     */
    bit16_t execute();

};

} // namespace
