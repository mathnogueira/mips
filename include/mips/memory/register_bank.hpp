/**
 * \file register_bank.hpp
 *
 * Arquivo contendo o banco de registradores contido no processador MIPS.
 *
 */
#pragma once

#include <mips/core.hpp>
#include <mips/memory/register.hpp>

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
	 * Cria uma instância do banco de registradores.
	 */
	RegisterBank();

	/**
	 * Destroi a instância do banco de registradores.
	 */
	~RegisterBank();

    /**
     * Retorna um ponteiro para o registrador identificado pelo código especificado.
     *
     * \param id código do registrador.
     * \return ponteiro para o registrador.
     */
    Register* getRegister(bit8_t id);

private:

    /**
     * Registradores para números inteiros.
     */
    Register *iRegister[8];

};

}; // namespace
