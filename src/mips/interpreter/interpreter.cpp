#include <mips/interpreter/interpreter.hpp>
#include <mips/interpreter/exception/interpreter_exception.hpp>
#include <mips/interpreter/encoder/encoder.hpp>
#include <mips/interpreter/encoder/encoder_factory.hpp>
#include <mips/interpreter/parser/tokenizer.hpp>
#include <mips/core.hpp>
#include <string>
#include <cstring>

using namespace MIPS;

Interpreter::Interpreter(const char* file) {
	// SpaceFilter spaceFilter;
	fileReader = new FileReader(file);
	errors = 0;
}

Interpreter::~Interpreter() {
	delete fileReader;
}

void Interpreter::processInput() {
	char *line = NULL;
	Tokenizer tokenizer;
	while (fileReader->hasNext()) {
		std::vector<char*> tokens;
		line = fileReader->next();
		tokenizer.tokenize(line, tokens);
		lines.push_back(tokens);
	}
	// Extraí todos os labels do código para que eles possam ser substituídos
	// futuramente.
	this->extractLabels();
	// Troca todos os labels pelo número da linha utilizando uma unidade relativa
	// Digamos:
	// i  :	LOOP:
	// i+1: 	addi $t0, $t0, 1
	// i+2: 	j LOOP
	// sendo i uma linha
	// isso se tornaria
	// i  : addi $t0, $t0, 1
	// i+1: j -1
	this->updateLabels();
	this->encode();
}

void Interpreter::extractLabels() {
	char* buffer, *endBuffer;
	char labelBuffer[64];
	unsigned long i = 0;
	while (i < lines.size()) {
		buffer = lines.at(i).at(0);
		if ((endBuffer = strchr(buffer, ':')) != NULL) {
			strncpy(labelBuffer, buffer, endBuffer - buffer);
			labelBuffer[endBuffer - buffer] = '\0';
			// Salva o label temporariamente para poder substituir suas ocorrencias
			// pelo numero da instrução que deverá ser executada.
			Label label;
			strcpy(label.label, labelBuffer);
			label.line = i;
			labels.push_back(label);
			// Remove o label
			lines.at(i).erase(lines.at(i).begin());
			// Checa se existe algo na linha, senao deleta a linha
			if (lines.at(i).size() == 0) {
				lines.erase(lines.begin() + i);
				--i;
			}
		}
		++i;
	}
}

void Interpreter::updateLabels() {
	unsigned long i = 0;
	char *param = NULL;
	while (i < lines.size()) {
		// Todas as instruções de assembly só têm labels no último parâmetro
		// da instrução, então só devemos olhar o último parâmetro.
		size_t numParams = lines.at(i).size();
		param = lines.at(i).at(numParams - 1);
		// Verifica se existe algum label
		for (unsigned int j = 0; j < labels.size(); ++j) {
			if (strcmp(param, labels.at(j).label) == 0) {
				int position = labels.at(j).line - i;
				char str[10];
				sprintf(str, "%d", position);
				lines.at(i).pop_back();
				lines.at(i).push_back(str);
			}
		}
		++i;
	}
}

void Interpreter::encode() {
	std::vector<char*> *tokens;
	EncoderFactory factory;
	Encoder *encoder;
	for (size_t i = 0; i < lines.size(); ++i) {
		tokens = &lines.at(i);
		encoder = factory.produce(tokens->at(0));
		encoder->parse(*tokens);
	}
}
