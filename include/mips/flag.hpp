/**
 * \file flag.hpp
 *
 * Arquivo contendo uma estrutura de dados que armazena as flags de saída
 * da ALU.
 */
#pragma once

#include <mips/core.hpp>

namespace MIPS {

/**
 * Estrutura que armazena as informações das flags de saída da ALU.
 */
struct ALUFlags {
    bit8_t zero;        ///< Flag de zero
    bit8_t carry;       ///< Flag de carry
    bit8_t neg;         ///< Flag de negativo
    bit8_t overflow;    ///< Flag de overflow
};

}
