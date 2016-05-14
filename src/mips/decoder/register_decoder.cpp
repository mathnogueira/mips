#include <mips/core.hpp>
#include <mips/decoder/register_decoder.hpp>
#include <cstdlib>

using namespace MIPS;

RegisterInstructionDecoder::RegisterInstructionDecoder() {}

RegisterInstructionDecoder::~RegisterInstructionDecoder() {}

Instruction* RegisterInstructionDecoder::decode(instruction32_t instruction) {
    return NULL;
}

/**
 * Função que recupera o endereço do registrador source (Rs)
 * da instrução.
 *
 * \param instruction instrução binária de 32 bits.
 * \return endereço do registrador source.
 */
bit8_t RegisterInstructionDecoder::getRs(instruction32_t instruction) {
    instruction = instruction <<= 6;
    return instruction >>= 27;
}

/**
 * Função que recupera o endereço do registrador target (Rt)
 * da instrução.
 *
 * \param instruction instrução binária de 32 bits.
 * \return endereço do registrador target.
 */
bit8_t RegisterInstructionDecoder::getRt(instruction32_t instruction) {
    return 0;
}

/**
 * Função que recupera o endereço do registrador destination (Rd)
 * da instrução.
 *
 * \param instruction instrução binária de 32 bits.
 * \return endereço do registrador destination.
 */
bit8_t RegisterInstructionDecoder::getRd(instruction32_t instruction) {
    return 0;
}

/**
 * Função que recupera o valor do shamt (shift amount) da instrução.
 *
 * \param instruction instrução binária de 32 bits.
 * \return quantidade de shift da instrução.
 */
bit8_t RegisterInstructionDecoder::getShamt(instruction32_t instruction) {
    return 0;
}

/**
 * Função que recupera o valor do funct da instrução.
 *
 * \param instruction instrução binária de 32 bits.
 * \return valor do funct
 */
bit8_t RegisterInstructionDecoder::getFunct(instruction32_t instruction) {
    return 0;
}
