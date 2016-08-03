/**
 * \file register.hpp
 *
 * Arquivo contendo a definição de um registrador.
 */
#pragma once

#include <mips/core.hpp>

namespace MIPS {

/**
 * Classe que representa um registrador de 16 bits.
 *
 * \author Matheus Nogueira
 */
class Register {

public:

	/**
	 * Cria um novo registrador.
	 *
	 * \param name nome do registrador.
	 * \param protect indica se o registrador é protegido para escrita.
	 */
	Register(const char* name, bool protect = false);

	/**
	 * Destroi o registrador.
	 */
	~Register();

	/**
	 * Define um valor que o registrador irá guardar.
	 *
	 * \param value valor 16 bits que será armazenado no registrador.
	 */
	void put(bit16_t value);

	/**
	 * Pega o valor 16 bits armazenado no registrador.
	 *
	 * \return valor armazenado no registrador.
	 */
	bit16_t get();

	/**
	 * Retorna o nome do registrador.
	 *
	 * \return nome do registrador.
	 */
	const char* getName();

private:

	/**
	 * Nome do registrador.
	 */
	const char* name;

    /**
     * Conteúdo do registrador.
     */
    bit16_t content;

	/**
	 * Indica se o registrador é protegido contra escrita.
	 */
	bool isProtected;

};

}; // namespace
