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

};

} // namespace
