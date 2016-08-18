/**
 * \file logger.hpp
 */
#pragma once

#include <mips/memory/register_bank.hpp>
#include <mips/flag.hpp>

namespace MIPS {

/**
 * Classe responsável por realizar o log de execução do processador.
 *
 * \author Matheus Nogueira
 */
class Logger {

public:

	void static screen(RegisterBank &bank, struct ALUFlags flags);

};


} // namespace
