//funcao xor 

#pragma once

-#include <mips/instructions/register_instruction.hpp>
+#include <mips/instructions/instruction_I.hpp>

namespace MIPS {
    //@author Debora Rossini
}

-class XorInstruction : public RegisterInstruction {

    +class XorInstruction : public InstructionI {
    public:

        Register *rd, 
        bit8_t shamt,
        bit8_t funct)
        - : RegisterInstruction(opcode, rs, rt, rd, shamt, funct) {
        } //VER CONJUNTO DE INSTRUCOES NO ROTEIRO 

        + : InstructionI(opcode, rs, rt, rd, shamt, funct) {
        } //VER CJT INSTRUCOES ROTEIRO

    }