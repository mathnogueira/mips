/**
 * \file jf_true.hpp
 *
 * Instrução que sempre faz o desvio.
 */
#pragma once

#include <mips/instructions/instruction_IV.hpp>

namespace MIPS {

/**
 * Instrução que sempre faz desvio.
 *
 * \author Felipe Dias
 */
class JfTrueInstruction : public InstructionIV {

public:

    /**
     * Cria uma instrução de jump on true.
     *
     * \param opcode código da operação
     * \param aluFlags objeto de flags da ALU
     * \param offset offset de 8 bits
     */
    JfTrueInstruction(bit8_t opcode, struct ALUFlags &aluFlags, bit8_t offset) :
            InstructionIV(opcode, aluFlags, offset) {}

    /**
     * Executa a instrução.
     *
     * \return returna 0 se o desvio for tomado, 1 se desvio não for tomado.
     */
    bit16_t execute();

};

} // namespace
