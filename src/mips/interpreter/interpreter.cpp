#include <mips/interpreter/interpreter.hpp>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace MIPS;

Interpreter::Interpreter(const char* file) {
	this->file = file;
	this->buffer = NULL;
}

Interpreter::~Interpreter() {
	if (this->buffer != NULL)
		delete[] this->buffer;
}

bool Interpreter::process() {
	char *buffer = NULL;
	char line[128];
	// Pega o conteúdo do arquivo especificado.
	this->loadFile();
	buffer = strtok(this->buffer, "\n");
	while (buffer != NULL) {
		// Remove espaços em branco no inicio e fim da linha.
		std::cout << buffer << std::endl;
		buffer = strtok(NULL, "\n");
	}
}

bool Interpreter::loadFile() {
	FILE *fp = fopen(this->file, "r");
	if (fp == NULL)
		return false;
	fseek(fp, 0L, SEEK_END);
	unsigned long fileSize = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	if (this->buffer != NULL) {
		delete[] this->buffer;
	}
	this->buffer = new char[fileSize];
	fread(this->buffer, sizeof(char), fileSize, fp);
	return true;
}
