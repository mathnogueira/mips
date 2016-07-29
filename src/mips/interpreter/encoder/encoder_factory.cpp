#include <mips/interpreter/encoder/encoder_factory.hpp>
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
	return &encoder1;
}
