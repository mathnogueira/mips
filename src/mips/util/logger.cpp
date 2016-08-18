#include <mips/util/logger.hpp>

using namespace MIPS;

void Logger::screen(MIPS::RegisterBank &bank, struct ALUFlags flags) {
	printf("-----------------------------------------------------------------\n");
	printf("                     STATUS DO PROCESSADOR                       \n");
	printf("\n");
	printf("  REGISTRADORES                             Flags                \n");
	printf("\n");
	printf("  r0  = %04x                                Neg         %d       \n", bank.getRegister(0)->get(), flags.neg);
	printf("  r1  = %04x                                Zero        %d       \n", bank.getRegister(0)->get(), flags.zero);
	printf("  r2  = %04x                                Carry       %d       \n", bank.getRegister(0)->get(), flags.carry);
	printf("  r3  = %04x                                NegZero     %d       \n", bank.getRegister(0)->get(), !flags.zero);
	printf("  r4  = %04x                                Overflow    %d       \n", bank.getRegister(0)->get(), flags.overflow);
	printf("  r5  = %04x                                                     \n", bank.getRegister(0)->get());
	printf("  r6  = %04x                                                     \n", bank.getRegister(0)->get());
	printf("  r7  = %04x                                                     \n", bank.getRegister(0)->get());
	printf("-----------------------------------------------------------------\n");
}
