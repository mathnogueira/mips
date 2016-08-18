/**
 * \file cpu.hpp
 *
 * Arquivo contendo uma estrutura que representa a CPU m-RISC.
 *
 */
#pragma once

#include <mips/memory/register_bank.hpp>
#include <mips/memory/memory.hpp>
#include <mips/units/instruction_finder.hpp>
#include <mips/units/control.hpp>
#include <mips/decoder/instruction_decoder.hpp>
#include <mips/flag.hpp>

namespace MIPS {

/**
 * Estrutura que armazena as opções para a execução do emulador.
 *
 */
struct options {
	bool screen;			///< Deve imprimir o estado de cada execução
	bool pause;				///< Deve pausar a tela quando ela encher
	bool dump;				///< Realiza o dump de memória ao final da execução
	bit16_t dump_start;		///< Posição inicial do dump
	bit16_t dump_size;		///< Número de palavras que serão impressas
};

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
	 *
	 * \param opt opções de execução do emulador
     */
    CPU(struct options &opt);

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

    /**
     * Executa as instruções carregadas previamente pelo método
     * loadProgram.
     *
     */
    void execute();

private:

    /**
     * Banco de memória do processador.
     */
    RegisterBank *bank;

    /**
     * Memória utilizada pela CPU.
     */
    Memory *memory;

    /**
     * Buscador de instruções.
     */
    InstructionFinder * instructionFinder;

    /**
     * Decoficador de instrução.
     */
    InstructionDecoder * instructionDecoder;

    /**
     * Unidade de controle de execução.
     */
    ControlUnit * controlUnit;

	/**
	 * Flags da ALU.
	 */
	struct ALUFlags aluFlags;

	/**
	 * Opções do emulador.
	 */
	struct options &options;
};

};
