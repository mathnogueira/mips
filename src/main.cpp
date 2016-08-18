#include <mips/cpu.hpp>
#include <mips/interpreter/interpreter.hpp>
#include <mips/interpreter/exception/interpreter_exception.hpp>
#include <cstdlib>
#include <cstring>


using namespace MIPS;

void optget(int args, char **argv, struct options &options) {
	options.dump = options.screen = options.pause = false;
	options.dump_size = 0;
	for (int i = 2; i < args; ++i) {
		if (strcmp("-s", argv[i]) == 0)
			options.screen = true;
		else if (strcmp("-p", argv[i]) == 0)
			options.pause = true;
		else if (strcmp("-d", argv[i]) == 0) {
			options.dump = true;
			options.dump_start = (bit16_t) strtol(argv[i+1], NULL, 16);
			options.dump_size = (bit16_t) atoi(argv[i+2]);
		}
	}
}

int main(int argc, char **argv) {
    if (argc < 2) {
		// Erro, deve indicar o arquivo que será executado.
		return -1;
	}
	// Pega as opções do interpretado
	struct options options;
	optget(argc, argv, options);
	printf("Dump %d : %d -> %d\n", options.dump, options.dump_start, options.dump_size);
	printf("Screen %d\n", options.screen);
	Interpreter interpreter(argv[1]);
    CPU cpu(options);
	try {
		interpreter.compile("out.mips");
	} catch (const std::runtime_error& exception) {
        std::cout << exception.what() << std::endl;
		// TODO: Criar um handler de erros.
	}
	if (interpreter.ok()) {
		// Continua o processo de emulação
        // Abre arquivo criado pelo interpretador e lê o seu conteúdo
        cpu.loadProgram("out.mips");
        cpu.execute();
	}
    return 0;
}
