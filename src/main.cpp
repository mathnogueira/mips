#include <mips/cpu.hpp>
#include <mips/interpreter/interpreter.hpp>
#include <mips/interpreter/exception/interpreter_exception.hpp>


using namespace MIPS;

int main(int argc, char **argv) {
    if (argc < 2) {
		// Erro, deve indicar o arquivo que será executado.
		return -1;
	}
	Interpreter interpreter(argv[1]);
    CPU cpu;
	try {
		interpreter.compile("out.mips");
    // Abre arquivo criado pelo interpretador e lê o seu conteúdo
    cpu.loadProgram("out.mips");
	} catch (const std::runtime_error& exception) {
        std::cout << exception.what() << std::endl;
		// TODO: Criar um handler de erros.
	}
	if (interpreter.ok()) {
		// Continua o processo de emulação
	}
    return 0;
}
