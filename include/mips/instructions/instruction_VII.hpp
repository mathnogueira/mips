/**
 * \file instruction_VII.hpp
 *
 * Arquivo descrevendo o formato de uma instrução do formato VII.
 */
#pragma once

#include <mips/core.hpp>
#include <mips/flag.hpp>
#include <mips/instructions/instruction.hpp>
#include <mips/memory/memory.hpp>
#include <mips/memory/register.hpp>

namespace MIPS {

/**
 * Classe que representa uma instrução do formato VII do trabalho.
 *
 * \author Matheus Nogueira
 */
class InstructionVII : public Instruction {

public:

    /**
     * Cria uma nova instrução do formato VII
     *
     * \param opcode código da operação
     * \param rs registrador destination
     * \param rt registrador target
     * \param memory unidade de memória do processador
     */
    InstructionVII(bit8_t opcode, Register *rs, Register *rt, Memory *memory) {
        this->opcode = opcode;
        this->rs = rs;
        this->rt = rt;
        this->memory = memory;
    }

    /**
     * Executa a instrução.
     *
     * \return resultado da instrução
     */
    virtual bit16_t execute() = 0;

protected:

    /**
     * Registrador source
     */
    Register *rs;

    /**
     * Registrador target.
     */
    Register *rt;

    /**
     * Unidade de memória usada para acessar os dados.
     */
    Memory *memory;

};

} // namespace
