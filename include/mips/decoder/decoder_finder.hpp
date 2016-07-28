/**
 * \file decoder_finder.hpp
 *
 * Arquivo que contém uma classe responsável por encontrar o decodificador
 * adequado para uma instrução do MIPS 16 bits.
 *
 */
#pragma once

#include <mips/core.hpp>
#include <mips/decoder/abstract_decoder.hpp>

namespace MIPS {

/**
 * Classe responsável por encontrar os decodificadores responsáveis por
 * decodificar uma determinada instrução 16 bits.
 *
 * \author Matheus Nogueira
 */
class DecoderFinder {

public:

    /**
     * Constrói um novo localizador de decodificadores.
     */
    DecoderFinder();

    /**
     * Destroi o localizador de decodificadores.
     */
    ~DecoderFinder();

    /**
     * Decodifica uma instrução qualquer.
     *
     * \param instruction instrução a ser decodificada.
     * \return instrução decodificada.
     */
    Instruction *decode(instruction_t instruction);

protected:

    /**
     * Retorna o decodificador adequado para a decodificação de uma instrução
     * 16 bits para a arquitetura do MIPS.
     *
     * \param instruction instrução que deve ser decodificada.
     * \return decodificador adequado para a instrução.
     */
    static InstructionDecoder *find(instruction_t instruction);

private:

    /**
     * Recupera o opcode da instrução.
     *
     * \param instruction instrução 16 bits
     * \return opcode da instrução.
     */
    static bit8_t getOPCode(instruction_t instruction) {
        return instruction >>= 26;
    }

};

}; // namespace
