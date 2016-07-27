/**
 * \file decoder.hpp
 *
 * Arquivo contendo um decodificador de instruções para a arquitetura MIPS de
 * 32 bits.
 *
 */
#pragma once

#include <mips/core.hpp>
#include <mips/instructions/instruction.hpp>
#include <mips/memory/register_bank.hpp>

namespace MIPS {

/**
 * Classe responsável por receber uma instrução em binário e instanciar uma
 * instrução do emulador que pode executar a instrução equivalente.
 *
 * \author Matheus Nogueira
 */
class InstructionDecoder {

public:
    /**
     * Cria um novo decodificador de instruções.
     */
    InstructionDecoder();

    /**
     * Destroi o decodificador de instruções.
     */
    ~InstructionDecoder();

    /**
     * Decodifica uma instrução em binário e cria uma instrução do emulador
     * que realize a operação equivalente.
     *
     * \param instruction instrução 32 bits em binário.
     * \return ponteiro para a instrução criada pelo emulador.
     */
    virtual Instruction *decode(instruction_t instruction);

protected:

	/**
	 * Banco de registradores do decodificador.
	 */
	RegisterBank *registerBank;

    /**
     * Método responsável por recuperar o código de operação (opcode) de
     * uma instrução.
     *
     * \param instruction instrução de onde o opcode deve ser extraído.
     * \return opcode da instrução.
     */
    bit8_t getOPCode(instruction_t instruction);

};

}; // namespace
