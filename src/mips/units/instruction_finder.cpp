#include <mips/units/instruction_finder.hpp>

using namespace MIPS;

InstructionFinder::InstructionFinder(Memory &memoryUnit, RegisterBank &bank) :
    pMemory(memoryUnit), pBank(bank) {}

InstructionFinder::~InstructionFinder() {}

instruction_t InstructionFinder::getNext() {
    bit16_t pc = pBank.getPC()->get();
    pBank.getPC()->put(pc + 1);
    return pMemory.read(pc, 0);
}
