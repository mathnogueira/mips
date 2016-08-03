/**
 * \file memory.hpp
 *
 * Arquivo contendo a estrutura responsável por encapsular a memória de ĩnstruções
 * e a memória de dados utilizada pelo processador.
 *
 */
#pragma once

#include <mips/core.hpp>

namespace MIPS {

/**
 * Classe responsável por iteragir com a memória do processador, para assim,
 * criar uma interface de maior facilidade para acessar a memória.
 *
 * \author Matheus Nogueira
 */
class Memory {

public:

    /**
     * Cria uma nova unidade de memória.
     */
    Memory();

    /**
     * Destroi a unidade de memória.
     */
    ~Memory();

    /**
     * Define o tamanho da memória de instruções.
     *
     * \param size tamanho da memória em número de palavras.
     */
    void setInstructionSize(size_t size);

    /**
     * Define o tamanho da memória de dados.
     *
     * \param size tamanho da memória em número de palavras.
     */
    void setDataSize(size_t size);

    /**
     * Escreve uma palavra na posição de memória especificada.
     *
     * \param data palavra que será escrita.
     * \param offset posição da memória em que a palavra será escrita.
     * \param iOrD tipo de dado que será escrito (instrução ou dados) (padrão: dado)
     */
    void write(bit16_t data, bit32_t offset, bit8_t iOrD = 1);

    /**
     * Lẽ uma palavra que está na posição de memória especificada.
     *
     * \param offset posição da memória que será lida.
     * \param iOrD tipo de dado que será lido (instruçao ou dado) (padrão: dado)
     * \return palavra armazenada na posição de memória especificada.
     */
    bit16_t read(bit32_t offset, bit8_t iOrD = 1);

private:

    /**
     * Memória que armazena instruções.
     */
    bit16_t *instructions;

    /**
     * Memória que armazena dados.
     */
    bit16_t *data;

    /**
     * Tamanho da memória de instruções.
     */
    size_t instructionsSize;

    /**
     * Tamanaho da memória de dados.
     */
    size_t dataSize;

};

} // namespace
