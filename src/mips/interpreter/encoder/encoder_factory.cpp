#include <mips/interpreter/encoder/encoder_factory.hpp>
#include <mips/interpreter/exception/interpreter_exception.hpp>
#include <cstring>

using namespace MIPS;

Encoder* EncoderFactory::produce(const char *instruction) {
	// Formato 7
	if (strcmp("load", instruction) == 0 || strcmp("store", instruction) == 0)
		return &encoder7;
	// Formato 6
	if (strcmp("jal", instruction) == 0 || strcmp("jr", instruction) == 0)
		return &encoder6;
	// Formato 5
	if (strcmp("j", instruction) == 0)
		return &encoder5;
	// Formato 4
	if (strcmp("jt.neg", instruction) == 0 			||
		strcmp("jt.zero", instruction) == 0 		||
		strcmp("jt.carry", instruction) == 0 		||
		strcmp("jt.negzero", instruction) == 0 		||
		strcmp("jt.true", instruction) == 0 		||
		strcmp("jt.overflow", instruction) == 0 	||
		strcmp("jf.neg", instruction) == 0 			||
		strcmp("jf.zero", instruction) == 0 		||
		strcmp("jf.carry", instruction) == 0 		||
		strcmp("jf.negzero", instruction) == 0 		||
		strcmp("jf.true", instruction) == 0 		||
		strcmp("jf.overflow", instruction) == 0)
		return &encoder4;
	// Formato 3
	if (strcmp("lcl", instruction) == 0 || strcmp("lch", instruction) == 0)
		return &encoder3;
	// Formato 2
	if (strcmp("loadlit", instruction) == 0)
		return &encoder2;
	// Formato 1
    if (strcmp("add", instruction) == 0 ||
        strcmp("addinc", instruction) == 0 ||
        strcmp("and", instruction) == 0 ||
        strcmp("andnota", instruction) == 0 ||
        strcmp("nand", instruction) == 0 ||
        strcmp("ornotb", instruction) == 0 ||
        strcmp("sub", instruction) == 0 ||
        strcmp("subdec", instruction) == 0 ||
		strcmp("nor", instruction) == 0 ||
        strcmp("xnor", instruction) == 0 ||
        strcmp("xor", instruction) == 0 ||
        strcmp("or", instruction) == 0 ||
        strcmp("asl", instruction) == 0 ||
        strcmp("asr", instruction) == 0 ||
        strcmp("deca", instruction) == 0 ||
        strcmp("inca", instruction) == 0 ||
        strcmp("lsl", instruction) == 0 ||
        strcmp("lsr", instruction) == 0 ||
        strcmp("passa", instruction) == 0 ||
        strcmp("passnota", instruction) == 0 ||
        strcmp("zeros", instruction) == 0 ||
        strcmp("ones", instruction) == 0)
	   return &encoder1;
    // Não existe a instrução
    char *err = new char[60];
    sprintf(err, "Instrução %s não existe", instruction);
    throw InterpreterException(err, 2);
}
