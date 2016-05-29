/**
 * \file label.hpp
 *
 * Arquivo contendo uma estrutura que armazena um label do codigo assembly.
 */
#pragma once

namespace MIPS {

/**
 * Estrutura que armazena o nome do label e a linha que ele se encontra.
 */
struct Label {
	char label[64];
	unsigned long line;
};

}; // namespace
