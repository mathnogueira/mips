/**
 * \file register_bank.hpp
 *
 * Arquivo contendo o banco de registradores contido no processador MIPS.
 *
 */
#pragma once

#include <mips/core.hpp>

namespace MIPS {

/**
 * Classe que representa o banco de registradores do MIPS. Esta é responsável
 * por gerenciar os registradores do processador.
 *
 * \author Matheus Nogueira
 */
class RegisterBank {

public:

    /**
     * Retorna um ponteiro para o registrador identificado pelo código especificado.
     *
     * \param id código do registrador.
     * \return ponteiro para o registrador.
     */
    Register *getRegister(bit8_t id);

private:

    /**
     * Registradores para números inteiros.
     */
    Register *iRegisters[32];

};

}; // namespace
