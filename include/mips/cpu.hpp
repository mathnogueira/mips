/**
 * \file cpu.hpp
 *
 * Arquivo contendo uma estrutura que representa a CPU MIPS.
 *
 */
#pragma once

namespace MIPS {

/**
 * Classe que representa o processador MIPS, esta é responsável por gerenciar
 * toda a execução da pipeline de execução das instruções do processador.
 *
 * \author Matheus Nogueira
 */
class CPU {

public:
    /**
     * Cria um novo processador MIPS.
     */
    CPU();

    /**
     * Destroi o processador MIPS.
     */
    ~CPU();

private:

    /**
     * Banco de memória do processador.
     */
    RegisterBank *bank;

    /**
     * Decofificador de instruções.
     */
    DecoderFinder *decoder;

};

};
