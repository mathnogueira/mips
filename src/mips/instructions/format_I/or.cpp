////////////////////////////
//Lucas Fonseca dos Santos//
////////////////////////////
//                        //
//      INSTRUÇÃO OR      //
//                        //
////////////////////////////
#include <mips/instructions/format_I/or.hpp>

using namespace MIPS;

void OrInstruction::execute()
{
	bit16_t rs = this->rs->get();    //Declara um rs tipo estrutura 16bits e pega o conteudo do registrador;
	bit16_t rt = this->rt->get();    //Declara um rt tipo estrutura 16bits e pega o conteudo do registrador;
	bit16_t result = rs | rt;        //Executa a operação referente a instrução trabalhada;
	this->rd->put(result);           //Insere resultado;
}
