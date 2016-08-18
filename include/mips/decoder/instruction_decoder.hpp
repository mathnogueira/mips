/**
 * \file instruction_decoder.hpp
 *
 * Arquivo contendo um decodificador de instruções para a arquitetura MIPS de
 * 16 bits.
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
     *
     * \param bank banco de registradores usado.
     */
    InstructionDecoder(RegisterBank &bank);

    /**
     * Destroi o decodificador de instruções.
     */
    ~InstructionDecoder();

    /**
     * Decodifica uma instrução em binário e cria uma instrução do emulador
     * que realize a operação equivalente.
     *
     * \param instruction instrução 16 bits em binário.
     * \return ponteiro para a instrução criada pelo emulador.
     */
    Instruction *decode(instruction_t instruction);

    /**
     * Método responsável por recuperar o código de operação (opcode) de
     * uma instrução.
     *
     * \param instruction instrução de onde o opcode deve ser extraído.
     * \return opcode da instrução.
     */
    bit8_t getOPCode(instruction_t instruction);

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
     * Função que recupera o valor do funct da instrução.
     *
     * \param instruction instrução binária de 16 bits.
     * \return valor do funct
     */
    bit8_t getFunct(instruction_t instruction);

	/**
	 * Pega o valor do codigo de diferenciação dos jumps.
	 *
	 * \param instruction instrução binária de 16 bits.
	 * \return valor de diferenciação.
	 */
	bit8_t getJumpOp(instruction_t instruction);

	/**
	 * Pega o valor de condição do jump.
	 *
	 * \param instruction instrução binária de 16 bits.
	 * \return valor do cond.
	 */
	bit8_t getJumpCond(instruction_t instruction);

    /**
     * Função que recupera o valor do offset da instrução.
     *
     * \param instruction instrução binária de 16 bits.
     * \param size número de bits de offset
     * \return valor do offset.
     */
    bit16_t getOffset(instruction_t instruction, bit8_t size = 8);

	/**
	 * Define a estrutura de flag da ALU.
	 *
	 * \param flags flags da ALU.
	 */
	void setALUFlags(struct ALUFlags *flags) {
		this->flags = flags;
	}


protected:

	/**
	 * Banco de registradores do decodificador.
	 */
	RegisterBank &registerBank;

	/**
	 * Flags da ALU.
	 */
	struct ALUFlags *flags;

};

}; // namespace
