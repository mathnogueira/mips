/**
 * \file encoder_factory.hpp
 *
 * Arquivo contendo um codificador MIPS 32 que cria um codificador apropriado para criar instruções
 * 32 bits, dependendo do comando da instrução.
 */
#pragma once

#include <mips/interpreter/encoder/encoder.hpp>
#include <mips/interpreter/encoder/r_encoder.hpp>
#include <mips/interpreter/encoder/i_encoder.hpp>
#include <mips/interpreter/encoder/j_encoder.hpp>
#include <mips/interpreter/label.hpp>
#include <vector>

namespace MIPS {

/**
 * Classe responsável por criar codificadores adequados para cada tipo de instrução.
 *
 * \author Matheus Nogueira
 */
class EncoderFactory {

public:

	/**
	 * Cria uma nova fábrica de codificadores para codificar o código assembly
	 * em código de máquina na arquitetura MIPS 32 bits.
	 *
	 * \param labels vector que contém todos os labels extraídos do código.
	 */
	EncoderFactory(std::vector<Label>& labels);

	/**
	 * Destroi a fábrica e todos os seus codificadores.
	 */
	~EncoderFactory();

	/**
	 * Cria um codificador a partir da operação solicitada.
	 *
	 * \param operation operação a ser realizada (comando assembly)
	 * \return ponteiro para o codificador adequado.
	 */
	Encoder* produce(const char* operation);

private:

	/**
	 * Codificador de instruções do tipo R.
	 */
	REncoder *rEncoder;

	/**
	 * Codificador de instruções do tipo I.
	 */
	IEncoder *iEncoder;

	/**
	 * Codificador de instruções do tipo J.
	 */
	JEncoder *jEncoder;

	/**
	 * Enumerado que facilita a identificação do tipo de instrução.
	 */
	enum InstructionType {
		R,		///< Instrução do tipo R
		I,		///< Instrução do tipo I
		J,		///< Instrução do tipo J	
	};

	/**
	 * Função usada para determinar se uma instrução assembly é do tipo
	 * R, I ou J.
	 *
	 * \param instruction nome da instrução assembly.
	 * \return tipo de instrução.
	 */
	InstructionType getInstructionType(const char *instruction);

	/**
	 * Função auxiliar para checar se a instrução é do tipo R.
	 *
	 * \param instruction nome da instrução.
	 * \return true se a instrução for do tipo R.
	 */
	bool isTypeR(const char* instruction);

	/**
	 * Função auxiliar para checar se a instrução é do tipo I.
	 *
	 * \param instruction nome da instrução.
	 * \return true se a instrução for do tipo I.
	 */
	bool isTypeI(const char* instruction);

	/**
	 * Função auxiliar para checar se a instrução é do tipo J.
	 *
	 * \param instruction nome da instrução.
	 * \return true se a instrução for do tipo J.
	 */
	bool isTypeJ(const char* instruction);


};

}; // namespace
