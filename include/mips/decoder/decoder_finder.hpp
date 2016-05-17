/**
 * \file decoder_finder.hpp
 *
 * Arquivo que contém uma classe responsável por encontrar o decodificador
 * adequado para uma instrução do MIPS 32 bits.
 *
 */
#pragma once

#include <mips/core.hpp>
#include <mips/decoder/abstract_decoder.hpp>

namespace MIPS {

/**
 * Classe responsável por encontrar os decodificadores responsáveis por
 * decodificar uma determinada instrução 32 bits.
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
    Instruction *decode(instruction32_t instruction);

protected:

    /**
     * Retorna o decodificador adequado para a decodificação de uma instrução
     * 32 bits para a arquitetura do MIPS.
     *
     * \param instruction instrução que deve ser decodificada.
     * \return decodificador adequado para a instrução.
     */
    static InstructionDecoder *find(instruction32_t instruction);

private:

    /**
     * Recupera o opcode da instrução.
     *
     * \param instruction instrução 32 bits
     * \return opcode da instrução.
     */
    static bit8_t getOPCode(instruction32_t instruction) {
        return instruction >>= 26;
    }

};

}; // namespace
