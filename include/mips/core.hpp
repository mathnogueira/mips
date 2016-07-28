/**
 * \file core.hpp
 *
 * Arquivo que contém tipos utilizados pelo emulaodr.
 */
#pragma once

#include <mips/debug.hpp>

namespace MIPS {

/**
 * Tipo que representa um inteiro de 8 bits.
 */
typedef signed char bit8_t;

/**
 * Tipo que representa um inteiro de 16 bits.
 */
typedef signed short bit16_t;

/**
 * Tipo que representa um inteiro de 16 bits.
 */
typedef signed int bit32_t;

/**
 * Tipo que representa uma instrução de 16 bits.
 */
typedef bit16_t instruction_t;

}
