/**
 * \file cpu.hpp
 *
 * Arquivo contendo uma estrutura que representa a CPU m-RISC.
 *
 */
#pragma once

#include <mips/decoder/decoder_finder.hpp>
#include <mips/memory/register_bank.hpp>
#include <mips/memory/memory.hpp>

namespace MIPS {

/**
 * Classe que representa o processador m-RISC, esta é responsável por gerenciar
 * toda a execução das instruções no processador.
 *
 * \author Matheus Nogueira
 */
class CPU {

public:
    /**
     * Cria uma nova CPU.
     */
    CPU();

    /**
     * Destroi a CPU.
     */
    ~CPU();

    /**
     * Carrega um programa na memória de instruções do processador.
     *
     * \param program caminho para o arquivo contendo o programa.
     */
    void loadProgram(const char *program);

private:

    /**
     * Banco de memória do processador.
     */
    RegisterBank *bank;

    /**
     * Decofificador de instruções.
     */
    DecoderFinder *decoder;

    /**
     * Memória utilizada pela CPU.
     */
    Memory *memory;

};

};
