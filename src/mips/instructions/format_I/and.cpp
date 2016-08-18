#include <mips/instructions/format_I/and.hpp>

using namespace MIPS;

bit16_t AndInstruction::execute() {
	bit16_t rs = this->rs->get();    //Declara um rs tipo estrutura 16bits e pega o conteudo do registrador;
	bit16_t rt = this->rt->get();    //Declara um rt tipo estrutura 16bits e pega o conteudo do registrador;
	bit16_t result = rs & rt;        //Executa a operação referente a instrução trabalhada;
	
    // Flags
    this->flags->neg = result < 0;
    this->flags->zero = result == 0;
    this->flags->carry = 0;
    this->flags->overflow = 0;
    
	return result;
}
