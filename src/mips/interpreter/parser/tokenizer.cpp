#include <mips/interpreter/parser/tokenizer.hpp>
#include <cstring>

using namespace MIPS;

void Tokenizer::tokenize(char *str, std::vector<char *> &vector) {
	char *token = strtok(str, "\t ,");
	while (token != NULL) {
		if (strlen(token) > 0) {
			vector.push_back(token);
		}
		token = strtok(NULL, "\t ,");
	}
}
