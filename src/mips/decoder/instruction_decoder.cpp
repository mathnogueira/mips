#include <mips/decoder/instruction_decoder.hpp>
#include <mips/instructions/format_I/add.hpp>
#include <mips/instructions/format_I/addinc.hpp>
#include <mips/instructions/format_I/and.hpp>
#include <mips/instructions/format_I/andnota.hpp>
#include <mips/instructions/format_I/asl.hpp>
#include <mips/instructions/format_I/asr.hpp>
#include <mips/instructions/format_I/deca.hpp>
#include <mips/instructions/format_I/inca.hpp>
#include <mips/instructions/format_I/nand.hpp>
#include <mips/instructions/format_I/nor.hpp>
#include <mips/instructions/format_I/ones.hpp>
#include <mips/instructions/format_I/or.hpp>
#include <mips/instructions/format_I/ornotb.hpp>
#include <mips/instructions/format_I/passa.hpp>
#include <mips/instructions/format_I/passnota.hpp>
#include <mips/instructions/format_I/sub.hpp>
#include <mips/instructions/format_I/subdec.hpp>
#include <mips/instructions/format_I/xnor.hpp>
#include <mips/instructions/format_I/xor.hpp>
#include <mips/instructions/format_I/zero.hpp>
#include <mips/instructions/format_II/loadlit.hpp>
#include <mips/instructions/format_III/lch.hpp>
#include <mips/instructions/format_III/lcl.hpp>
#include <mips/instructions/format_V/j.hpp>
#include <cstdlib>
#include <cmath>

using namespace MIPS;

InstructionDecoder::InstructionDecoder(RegisterBank &bank) : registerBank(bank) {}

InstructionDecoder::~InstructionDecoder() {}

Instruction* InstructionDecoder::decode(instruction_t instruction) {
    bit8_t opcode = getOPCode(instruction);
    bit8_t funct = getFunct(instruction);
    bit16_t offset;
	bit8_t cond = 0;
    // Lê os dois registradores
    Register *rs = registerBank.getRegister(getRs(instruction));
    Register *rt = registerBank.getRegister(getRt(instruction));
    Register *rd = registerBank.getRegister(getRd(instruction));
    Instruction *instr = NULL;
	PRINT_BIN(instruction);
    printf("OPCODE: %d\n", opcode);
    printf("FUNCT: %d\n", funct);
    switch (opcode) {
        case 0:
			funct = getJumpOp(instruction);
			//cond = getJumpCond(instruction);
			printf("FUNCT: %d\n", funct);
            // Instruções de JUMP condicional ou incondicionais
            // Jal e JR
            // Verifica os códigos de função
            if (funct == 0) {
                // JF.cond, deve checar o código da condição
				if (cond == 4)
					// Neg
				if (cond == 5)
					// Zero
				if (cond == 6)
					// Carry
				if (cond == 7)
					// Negzero
				if (cond == 0)
					// True
				if (cond == 3)
					// Overflow
					;
            } else if (funct == 1) {
                // JT.cond, deve checar o código da condição
				if (cond == 4)
					// Neg
				if (cond == 5)
					// Zero
				if (cond == 6)
					// Carry
				if (cond == 7)
					// Negzero
				if (cond == 0)
					// True
				if (cond == 3)
					// Overflow
					;
            } else if (funct == 2) {
				DEBUG("Jump");
                return new JumpInstruction(opcode, getOffset(instruction, 12));
            } else if (funct == 3) {
                // Pode ser tanto jal, como pode ser jr. Deve checar o campo R.
                bit8_t r = (instruction >> 10) & 1;
                if (r) {
                    // JR
                } else {
                    // JAL
                }
            }
            break;
        case 1:
            // Instruções do formato I e acesso à memória
            switch (funct) {
                case 0:
                    // Zeros
                    instr = new ZeroInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 1:
                    // Ones
                    instr = new OnesInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 2:
                    // And
                    instr = new AndInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 3:
                    // Nand
                    instr = new NandInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 4:
                    // Or
                    instr = new OrInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 5:
                    // Nor
                    instr = new NorInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 6:
                    // Xor
                    instr = new XorInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 7:
                    // Xnor
                    instr = new XnorInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 8:
                    // passnota
                    instr = new PassNotAInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 9:
                    // passa
                    instr = new PassaInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 10:
                    // andnota
                    instr = new AndnotaInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 11:
                    // ornotb
                    instr = new OrnotbInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 16:
                    // lsl
                    // instr = new LslInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 17:
                    // asl
                    instr = new AslInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 18:
                    // lsr
                    // instr = new LsrInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 19:
                    // asr
                    instr = new AsrInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 20:
                    // load
                    // instr = new LoadInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 22:
                    // store
                    break;
                case 24:
                    // Add
                    instr = new AddInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 25:
                    // Sub
                    instr = new SubInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 26:
                    // Addinc
                    instr = new AddIncInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 27:
                    // Subdec
                    instr = new SubdecInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 28:
                    // Inca
                    instr = new IncaInstruction(opcode, rs, rt, 0, funct);
                    break;
                case 29:
                    // Deca
                    instr = new DecaInstruction(opcode, rs, rt, 0, funct);
                    break;
            }
            break;
        case 2:
            // Loadlit
            offset = getOffset(instruction, 11);
            instr = new LoadlitInstruction(opcode, rd, offset);
            break;
        case 3:
            // LCL e LCH
            // Verifica campo R
            bit8_t r = (instruction >> 10) & 1;
            offset = getOffset(instruction, 8);
            if (r) {
                // LCH
                instr = new LchInstruction(opcode, rd, offset);
            } else {
                // LCL
                instr = new LclInstruction(opcode, rd, offset);
            }
            break;
    }
    return instr;
}

bit8_t InstructionDecoder::getOPCode(instruction_t instruction) {
    // shift de 14 casas pra direita: pega as 2 casas mais significativas
    return (instruction >> 14) & 0x0003;
}

/**
 * Função que recupera o endereço do registrador source (Rs)
 * da instrução.
 *
 * \param instruction instrução binária de 16 bits.
 * \return endereço do registrador source.
 */
bit8_t InstructionDecoder::getRs(instruction_t instruction) {
    return (instruction >> 3) & 0x0007;
}

/**
 * Função que recupera o endereço do registrador target (Rt)
 * da instrução.
 *
 * \param instruction instrução binária de 16 bits.
 * \return endereço do registrador target.
 */
bit8_t InstructionDecoder::getRt(instruction_t instruction) {
    return instruction & 0x0007;
}

/**
 * Função que recupera o endereço do registrador destination (Rd)
 * da instrução.
 *
 * \param instruction instrução binária de 16 bits.
 * \return endereço do registrador destination.
 */
bit8_t InstructionDecoder::getRd(instruction_t instruction) {
    return (instruction >> 11) & 0x0007;
}

/**
 * Função que recupera o valor do funct da instrução.
 *
 * \param instruction instrução binária de 16 bits.
 * \return valor do funct
 */
bit8_t InstructionDecoder::getFunct(instruction_t instruction) {
    return (instruction >> 6) & 0x001f;
}

/**
 * Pega o valor do codigo de diferenciação dos jumps.
 *
 * \param instruction instrução binária de 16 bits.
 * \return valor de diferenciação.
 */
bit8_t InstructionDecoder::getJumpOp(instruction_t instruction) {
	return (instruction >> 12) & 0x0003;
}

/**
 * Pega o valor de condição do jump.
 *
 * \param instruction instrução binária de 16 bits.
 * \return valor do cond.
 */
bit8_t InstructionDecoder::getJumpCond(instruction_t instruction) {
	return (instruction >> 8) & 0x000f;
}

/**
 * Função que recupera o valor do offset da instrução.
 *
 * \param instruction instrução binária de 16 bits.
 * \param size número de bits de offset
 * \return valor do offset.
 */
bit16_t InstructionDecoder::getOffset(instruction_t instruction, bit8_t size) {
    return instruction & (bit16_t)(pow(2, size)-1);
}
