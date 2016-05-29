/**
 * \file file_reader.hpp
 *
 * Arquivo contendo uma classe responsável por ler e limpar o conteúdo de um
 * arquivo do disco.
 */
#pragma once

#include <mips/util/filter/filter.hpp>
#include <fstream>
#include <vector>

namespace MIPS {

/**
 * Classe responsável por ler o conteúdo de um arquivo e salvá-lo internamente,
 * fazendo com que seja simples para obter as informações do mesmo.
 *
 * \author Matheus Nogueira
 */
class FileReader {

public:

	/**
	 * Cria um novo leitor de arquivo.
	 *
	 * \param filename nome do arquivo a ser lido.
	 */
	FileReader(const char *filename);

	/**
	 * Cria um novo leitor de arquivo que filtra determinadas entradas.
	 *
	 * \param filename nome do arquivo a ser lido.
	 * \param filter filtro a ser utilizado.
	 */
	FileReader(const char *filename, Filter &filter);

	/**
	 * Destroi o leitor de arquivo e o conteúdo do buffer interno.
	 */
	~FileReader();

	/**
	 * Retorna a proxima linha do arquivo.
	 *
	 * \return proxima linha do arquivo.
	 */
	char* next();

	/**
	 * Retorna o ponteiro da linha atual para o inicio do arquivo.
	 */
	void rewind();

	/**
	 * Checa se o arquivo ainda tem conteúdo para ser lido.
	 *
	 * \return booleano que se true, indica que ainda existe linhas a ser lidas.
	 */
	bool hasNext();

private:

	/**
	 * Leitor de arquivo interno.
	 */
	std::ifstream file;

	/**
	 * Filtro que será utilizado pelo leitor de arquivos.
	 */
	Filter *filter;

	/**
	 * Ultima linha retornada.
	 */
	unsigned long currentLine;

	/**
	 * Buffer interno para armazenar o conteúdo do arquivo.
	 */
	std::vector<char*> buffer;

	/**
	 * Abre e salva o conteúdo de um arquivo no buffer.
	 *
	 * \param filename nome do arquivo.
	 */
	void readFile(const char* filename);

};

}; // namespace
