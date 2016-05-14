/**
 * \file register_bank.hpp
 *
 * Arquivo contendo o banco de registradores contido no processador MIPS.
 *
 */
#pragma once

namespace MIPS {

/**
 * Classe que representa o banco de registradores do MIPS. Esta é responsável
 * por gerenciar os registradores do processador.
 *
 * \author Matheus Nogueira
 */
class RegisterBank {

private:

    /**
     * Registradores para números inteiros.
     */
    Register *iRegisters[32];

};

}; // namespace
