//funcao passnota

#pragma once

-#include <mips/instructions/register_instruction.hpp>
+#include <mips/instructions/instruction_I.hpp>

namespace MIPS {
    //@author Debora Rossini

    -class PassnotaInstruction : public RegisterInstruction {

        +class PassnotaInstruction : public InstructionI {
        public:

            Register *rd, 
            bit8_t shamt,
            bit8_t funct)
            - : RegisterInstruction(opcode, rs, rt, rc, shamt, funct) {
            } //PEGAR CONJ INSTRUCOES ROTEIRO

            + : InstructionI(opcode, rs, rt, rc, shamt, funct) {
            } //PEGAR CJT INSTRUCOES ROTEIRO
        }
