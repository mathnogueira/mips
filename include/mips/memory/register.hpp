/**
 * \file register.hpp
 *
 * Arquivo contendo a definição de um registrador.
 */
#pragma once

#include <mips/core.hpp>
#include <string>

namespace MIPS {

/**
 * Classe que representa um registrador de 32 bits.
 *
 * \author Matheus Nogueira
 */
class Register {

public:

    /**
     * Cria um novo registrador com um alias.
     *
     * \param alias nome do registrador.
     */
    Register(const char* alias) { Register(alias, false); }

    /**
     * Cria um novo registrador com um alias.
     *
     * \param alias nome do registrador.
     * \param protected indica que o indicador não pode ser atualizado.
     */
    Register(const char* alias, bool protected);

private:

    /**
     * Alias do registrador.
     */
    std::string alias;

    /**
     * Flag que indica que o registrador é protegido, portanto, ele não pode
     * ser sobre-escrito.
     */
    bool protected;

    /**
     * Conteúdo do registrador.
     */
    bit32_t content;

};

}; // namespace
