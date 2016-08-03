/**
 * \file instruction_finder.hpp
 *
 * Arquivo contendo o buscador de instruções do processador.
 *
 */
#pragma once

#include <mips/core.hpp>
#include <mips/memory/memory.hpp>
#include <mips/memory/register_bank.hpp>

namespace MIPS {

/**
 * Classe que representa a unidade de busca de instruções na memória.
 *
 * \author Matheus Nogueira
 */
class InstructionFinder {

public:

    /**
     * Cria uma nova unidade para busca de instruções.
     */
    InstructionFinder(Memory &memoryUnit, RegisterBank &bank);

    /**
     * Destroi a unidade de busca de instruções.
     */
    ~InstructionFinder();

    /**
     * Retorna a próxima instrução a ser executada, utilizando o registrador
     * PC para identificá-la.
     *
     * \return próxima instrução a ser executada.
     */
    instruction_t getNext();

private:

    /**
     * Unidade de memória usada para buscar as instruções.
     */
    Memory &pMemory;

    /**
     * Banco de registradores para acessar o registrador de PC.
     */
    RegisterBank &pBank;

};

} // namespace
