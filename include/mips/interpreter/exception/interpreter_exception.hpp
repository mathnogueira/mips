/**
 * \file InterpreterException
 *
 * Arquivo contendo uma exceção que é lançada pelo interpretador de assembly.
 *
 */
#pragma once

#include <exception>
#include <stdexcept>
#include <mips/core.hpp>

namespace MIPS {

/**
 * Exceção que é lançada pelo interpretador quando um erro é encontrado no arquivo
 * fonte.
 *
 * \author Matheus Nogueira
 */
class InterpreterException : public std::runtime_error {

public:

	/**
	 * Cria uma nova exceção.
	 *
	 * \param msg mensagem de erro.
	 * \param opcode código do erro.
	 */
	InterpreterException(const char* msg, bit8_t opcode):
		runtime_error(msg), pMsg(msg), pOpcode(opcode) {
	}

	~InterpreterException() {
		delete pMsg;
	}

	/**
	 * Retorna a mensagem de erro.
	 *
	 * \return mensagem de erro.
	 */
	virtual const char* what() const throw() {
		return pMsg;
	}

	/**
	 * Retorna o codigo de operação da exceção.
	 *
	 * \return codigo de operação.
	 */
	bit8_t getCode() {
		return pOpcode;
	}

private:

	/**
	 * Mensagem de erro.
	 */
	const char* pMsg;

	/**
	 * Código do erro.
	 */
	bit8_t pOpcode;

};

}; // namespace
