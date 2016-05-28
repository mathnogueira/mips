#include <mips/core.hpp>
#include <mips/decoder/decoder_finder.hpp>

using namespace MIPS;

int main(int argc, char **argv) {
    instruction32_t instruction = 0xac000000;
    DecoderFinder finder;
    finder.decode(instruction);
    return 0;
}
