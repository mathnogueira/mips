/**
 * \file debug.hpp
 *
 * Arquivo que contém funções para auxiliar o processo de DEBUG da execução
 * do emulador.
 *
 */
#pragma once

#include <iostream>
#include <cstdio>
#include <mips/core.hpp>

namespace MIPS {

    #ifndef NDEBUG
        // Está no modo DEBUG
        #define MESSAGE(arg) {                                                 \
            std::cout << arg << std::endl;                                     \
        }

        #define DEBUG(arg) {                                                 	\
            std::cout << "[DEBUG] " << arg << std::endl;                        \
        }

        #define FORMAT_DEBUG(format, ...) {                                     \
            printf(format, __VA_ARGS__);                                          \
        }

		// Imprime binário
		#define PRINT_BIN(num) {					\
			char x09878412bin = 0;					\
			char i = 15;							\
			for (; i >= 0; --i) {					\
				x09878412bin = (num >> i) & 1;		\
				printf("%d", x09878412bin);			\
				if (i % 4 == 0)							\
					printf(" ");					\
			}										\
			printf("\n");							\
		}
    #else
        // Não está em debug (cria macros falsas)
        #define MESSAGE(arg) ;
        #define DEBUG(arg) ;
		#define PRINT_BIN(num) ;
    #endif

}; // namespace
