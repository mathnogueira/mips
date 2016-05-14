/**
 * \file debug.hpp
 *
 * Arquivo que contém funções para auxiliar o processo de DEBUG da execução
 * do emulador.
 *
 */
#pragma once

#include <iostream>

namespace MIPS {

    #ifndef NDEBUG
        // Está no modo DEBUG
        #define MESSAGE(arg) {                                                 \
            std::cout << arg << std::endl;                                     \
        }

        #define DEBUG(arg) {                                                 \
            std::cout << "[DEBUG] " << arg << std::endl;                                     \
        }
    #else
        // Não está em debug (cria macros falsas)
        #define MESSAGE(arg) ;
        #define DEBUG(arg) ;
    #endif

}; // namespace
