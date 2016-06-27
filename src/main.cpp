#include <mips/interpreter/interpreter.hpp>
#include <mips/interpreter/exception/interpreter_exception.hpp>

using namespace MIPS;

int main(int argc, char **argv) {
    if (argc < 2) {
		// Erro, deve indicar o arquivo que será executado.
		return -1;
	}
	Interpreter interpreter(argv[1]);
	try {
		interpreter.processInput();
	} catch (InterpreterException& exception) {
		// TODO: Criar um handler de erros.
	}
	if (interpreter.ok()) {
		// Continua o processo de emulação
	}
    return 0;
}
