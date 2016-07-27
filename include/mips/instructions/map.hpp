/**
 * \file map.hpp
 *
 * Arquivo que contém o mapa de todas as instruções do MIPS.
 */
#pragma once

#include <mips/core.hpp>
#include <iterator>
#include <algorithm>
#include <cstdio>

namespace MIPS {

/**
 * Mapa das instruções do tipo R.
 */
const bit8_t rInstructions[] = {
    1,2,3, 43
};

/**
 * Mapa das instruções do tipo I.
 */
const bit8_t iInstructions[] = {
    100
};

/**
 * Mapa das instruções do tipo J.
 */
const bit8_t jInstructions[] = {
    120
};

inline bool Instruction_isR(bit8_t instruction) {
    size_t size = sizeof(rInstructions) / sizeof(*rInstructions);
    for (size_t i = 0; i < size; ++i) {
        if (instruction == rInstructions[i])
            return true;
    }
    return false;
}

inline bool Instruction_isI(bit8_t instruction) {
    size_t size = sizeof(iInstructions) / sizeof(*iInstructions);
    for (size_t i = 0; i < size; ++i) {
        if (instruction == iInstructions[i])
            return true;
    }
    return false;
}

inline bool Instruction_isJ(bit8_t instruction) {
    size_t size = sizeof(jInstructions) / sizeof(*jInstructions);
    for (size_t i = 0; i < size; ++i) {
        if (instruction == jInstructions[i])
            return true;
    }
    return false;
}

}; // namespace
