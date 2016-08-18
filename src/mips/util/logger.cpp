#include <mips/util/logger.hpp>

using namespace MIPS;

void Logger::screen(MIPS::RegisterBank &bank, struct ALUFlags flags, instruction_t instruction) {
	printf("-----------------------------------------------------------------\n");
	printf("                     STATUS DO PROCESSADOR                       \n");
	printf("\n");
	printf("  REGISTRADORES                             Flags                \n");
	printf("\n");
	printf("  r0  = %04x                      \t\tNeg         %d       \n", bank.getRegister(0)->get(), flags.neg);
	printf("  r1  = %04x                      \t\tZero        %d       \n", bank.getRegister(1)->get(), flags.zero);
	printf("  r2  = %04x                      \t\tCarry       %d       \n", bank.getRegister(2)->get(), flags.carry);
	printf("  r3  = %04x                      \t\tNegZero     %d       \n", bank.getRegister(3)->get(), !flags.zero);
	printf("  r4  = %04x                      \t\tOverflow    %d       \n", bank.getRegister(4)->get(), flags.overflow);
	printf("  r5  = %04x                                                     \n", bank.getRegister(5)->get());
	printf("  r6  = %04x                                                     \n", bank.getRegister(6)->get());
	printf("  r7  = %04x                                                     \n", bank.getRegister(7)->get());
	printf("\n");
	printf("                          PC = %04x                              \n", bank.getPC()->get());
	printf("                          IR = ????                              \n");
	printf("\n");
	printf("                   Instrução executada = %04x                    \n", instruction);
	printf("-----------------------------------------------------------------\n");
}

void Logger::dump(Memory &memory, bit16_t start, bit16_t size) {
	bit16_t end = start + size;
	bit16_t togo = size;
	bit8_t s = 0;
	printf("-----------------------------------------------------------------\n");
	printf("                       STATUS DA MEMÓRIA                         \n");
	printf("\n");
	for (bit16_t i = 0; i < size; i += 4) {
		printf(" %04x:\t", start + i * 2);
		s = (togo > 4) ? 4 : togo;
		for (bit8_t j = 0; j < s; ++j) {
			printf("%04x\t", memory.read(start + 4*i + j));
		}
		togo -= 4;
		printf("\n");
	}
}
