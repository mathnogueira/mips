/**
 * \file encoder_factory.hpp
 *
 * Arquivo contendo uma fábrica de codificadores de instruções.
 */
#pragma once

#include <mips/interpreter/encoder/encoder.hpp>
#include <mips/interpreter/encoder/format_I_encoder.hpp>
#include <mips/interpreter/encoder/format_II_encoder.hpp>
#include <mips/interpreter/encoder/format_III_encoder.hpp>
#include <mips/interpreter/encoder/format_IV_encoder.hpp>
#include <mips/interpreter/encoder/format_V_encoder.hpp>
#include <mips/interpreter/encoder/format_VI_encoder.hpp>
#include <mips/interpreter/encoder/format_VII_encoder.hpp>

namespace MIPS {

/**
 * Fábrica responsável por referenciar os codificadores corretos para cada
 * instrução da linguagem de montagem do micro-RISC.
 *
 * \author Matheus Nogueira
 */
class EncoderFactory {

public:

	/**
	 * Cria uma nova fábrica de codificadores.
	 */
	EncoderFactory() {}

	/**
	 * Produz um codificador para determinada instrução.
	 *
	 * \param instruction nome da instrução que deve ser codificada.
	 */
	Encoder* produce(const char* instruction);

private:

	/**
	 * Codificador de instruções do formato 1
	 */
	FormatIEncoder encoder1;

	/**
	 * Codificador de instruções do formato 2
	 */
	FormatIIEncoder encoder2;

	/**
	 * Codificador de instruções do formato 3
	 */
	FormatIIIEncoder encoder3;

	/**
	 * Codificador de instruções do formato 4
	 */
	FormatIVEncoder encoder4;

	/**
	 * Codificador de instruções do formato 5
	 */
	FormatVEncoder encoder5;

	/**
	 * Codificador de instruções do formato 6
	 */
	FormatVIEncoder encoder6;

	/**
	 * Codificador de instruções do formato 7
	 */
	FormatVIIEncoder encoder7;

};

} // namespace
