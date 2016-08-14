/**
 * \file store.hpp
 *
 * Instrução de Store, carrega na posição da memória endereçada pelo 
 * registrador X o conteúdo do registrador Y.
 */
#pragma once

#include <mips/instructions/instruction_VII.hpp>

namespace MIPS {

/**
 * Instrução de Store, carrega na posição da memória endereçada pelo 
 * registrador X o conteúdo do registrador Y.
 *
 * \author Felipe Dias
 */
class StoreInstruction : public InstructionVII {

public:
    /**
     * Constroi uma nova instrução.
     */
     StoreInstruction(bit8_t opcode,
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

};

} // namespace
