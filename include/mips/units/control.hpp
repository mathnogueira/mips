/**
 * \file control.hpp
 *
 * Arquivo contendo a unidade de controle do processador.
 */
#pragma once

namespace MIPS {

/**
 * Unidade de controle do processador. Essa unidade é responsável por setar
 * todas as flags que serão utilizadas para executar uma instrução.
 *
 * \author Matheus Nogueira
 */
class ControlUnit {

public:

    /**
     * Cria uma nova unidade de controle.
     */
    ControlUnit();

    /**
     * Destroi a unidade de controle.
     */
    ~ControlUnit();

	/**
	 * Reseta as flags do controle.
	 */
	void reset();

	/**
	 * Flag que indica o registrador de destino.
	 */
	bool regDst;

    /**
     * Flag de escrita em banco de registradores.
     */
    bool regwrite;

	/**
	 * Flag que indica que haverá leitura de memória.
	 */
	bool memRead;

	/**
	 * Flag que indica que haverá escrita na memória.
	 */
	bool memWrite;

    /**
     * Flag de branch.
     */
    bool branch;

    /**
     * Flag de jump
     */
    bool jump;

};

} // namespace
