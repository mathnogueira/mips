/**
 * \file memory_exception.hpp
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
 * Exceção que é lançada pelo interpretador quando um erro é encontrado durante
 * o acesso à memória.
 *
 * \author Matheus Nogueira
 */
class MemoryException : public std::runtime_error {

public:

	/**
	 * Cria uma nova exceção.
	 *
	 * \param msg mensagem de erro.
	 */
	MemoryException(const char* msg):
		runtime_error(msg), pMsg(msg) {
	}

	~MemoryException() {}

	/**
	 * Retorna a mensagem de erro.
	 *
	 * \return mensagem de erro.
	 */
	virtual const char* what() const throw() {
		return pMsg;
	}

private:

	/**
	 * Mensagem de erro.
	 */
	const char* pMsg;

};

}; // namespace
