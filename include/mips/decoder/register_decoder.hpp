/**
 * \file register_decoder.hpp
 *
 * Decodificador de instruções do tipo register (R).
 *
 */
#pragma once

#include <mips/decoder/abstract_decoder.hpp>
#include <mips/instructions/instruction.hpp>

namespace MIPS {

/**
 * Classe responsável por decofificar instruções do tipo (R)egister e criar
 * a instrução responsável por executar a instrução equivalente no emulador.
 *
 * \author Matheus Nogueira
 */
class InstructionIDecoder : public InstructionDecoder {

public:

    /**
     * Cria um novo decodificador de instruções register.
     */
    InstructionIDecoder();

    /**
     * Destroi o decodificador.
     */
    ~InstructionIDecoder();

    /**
     * Decodifica uma instrução de 16 bits no formato de uma instrução do tipo R.
     *
     * \param instruction instrução a ser decodificada.
     * \return instrução equivalente do emulador.
     */
    Instruction *decode(instruction_t instruction);

protected:

    /**
     * Função que recupera o endereço do registrador source (Rs)
     * da instrução.
     *
     * \param instruction instrução binária de 16 bits.
     * \return endereço do registrador source.
     */
    bit8_t getRs(instruction_t instruction);

    /**
     * Função que recupera o endereço do registrador target (Rt)
     * da instrução.
     *
     * \param instruction instrução binária de 16 bits.
     * \return endereço do registrador target.
     */
    bit8_t getRt(instruction_t instruction);

    /**
     * Função que recupera o endereço do registrador destination (Rd)
     * da instrução.
     *
     * \param instruction instrução binária de 16 bits.
     * \return endereço do registrador destination.
     */
    bit8_t getRd(instruction_t instruction);

    /**
     * Função que recupera o valor do shamt (shift amount) da instrução.
     *
     * \param instruction instrução binária de 16 bits.
     * \return quantidade de shift da instrução.
     */
    bit8_t getShamt(instruction_t instruction);

    /**
     * Função que recupera o valor do funct da instrução.
     *
     * \param instruction instrução binária de 16 bits.
     * \return valor do funct
     */
    bit8_t getFunct(instruction_t instruction);

};

}; // namespace
