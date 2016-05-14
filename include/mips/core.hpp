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
typedef unsigned char bit8_t;

/**
 * Tipo que representa um inteiro de 16 bits.
 */
typedef unsigned short bit16_t;

/**
 * Tipo que representa um inteiro de 32 bits.
 */
typedef unsigned int bit32_t;

/**
 * Tipo que representa uma instrução de 32 bits.
 */
typedef bit32_t instruction32_t;

}
