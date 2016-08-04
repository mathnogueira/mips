# Emulador de uRISC 16 bits
Emulador do processador uRISC de 16 bits para a disciplina GCC117 - Arquitetura de Computadores.

[![Build Status](https://travis-ci.org/mathnogueira/mips.svg?branch=master)](https://travis-ci.org/mathnogueira/mips)

## Tabela de conteúdo
1. [Estrutura do projeto](#estrutura-do-projeto)
2. [Documentação Doxygen](http://htmlpreview.github.io/?https://github.com/mathnogueira/mips/blob/master/docs/html/index.html)
3. [Ferramentas necessárias](#ferramentas-necessárias)
4. [Compilando o projeto](#compilando-o-projeto)
	1. [Compilando e executando o projeto](#compilando-e-executando-o-projeto)
	2. [Compilando e executando testes unitários](#compilando-e-executando-testes-unitários)
5. [Usando o git](#usando-o-git)
6. [Tabela de instruções](#tipos-de-instruções)
	1. [Tipo 1](#tipo-1)
	2. [Tipo 2](#tipo-2)
	3. [Tipo 3](#tipo-3)
	4. [Tipo 4](#tipo-4)
	5. [Tipo 5](#tipo-5)
	6. [Tipo 6](#tipo-6)
	7. [Tipo 7](#tipo-7)

## Estrutura do projeto

| Diretório		| Função																| Links		|
| :-----------  |:--------------------------------------------------------------------- | :-------- |
| build			| Pasta que organiza todos os arquivos gerados pelo sistema de build    |           |
| include 		| Pasta que contém todos os cabeçalhos de classes e funções				|			|
| libs			| Pasta que contém todas as bibliotecas externas usadas no projeto		|			|
| src			| Pasta que contém todas as implementações do projeto					|			|
| tests			| Pasta contendo todos os arquivos de teste automatizado				| [projeto gtest](https://github.com/google/googletest),  [tutorial](http://www.ibm.com/developerworks/aix/library/au-googletestingframework.html) |
| CMakeLists.txt| Arquivo de configuração do cmake para automatizar a construção do projeto|        |

## Ferramentas necessárias
* g++ (compatível com o c++98)
* cmake 2.6+
* make

## Compilando o projeto

Antes de qualquer coisa, crie a pasta build do projeto. Para isso, abra o terminal
e digite:
```shell
$ mkdir build && cd build
```

### Compilando e executando o projeto
```shell
$ cmake .. && make
$ ./mips
```

### Compilando e executando testes unitários
```shell
$ cmake -Dtest=ON .. && make
$ ./mips_test
```

## Usando o git

Para começar a colaborar com o projeto, crie sua branch no projeto. Para isso, abra o terminal
e digite:

```shell
$ git checkout -b branch-SEUNOME
```

Para subir alterações do seu código no github, digite na pasta raíz do projeto:

```shell
$ git add .
$ git commit -m "Uma mensagem do que você fez"
$ git push origin branch-SEUNOME
```

## Tipos de instruções

### Tipo 1

| Instrução | OPcode| Rd | Funct  | Rs | Rt | Status | Formato           |
|:---------:|:-----:|:--:|:------:|:--:|:--:|:------:|:-----------------:|
| add       | 01    | RD | 11000  | RS | RT |   OK   | add rd, rs, rt    |
| addinc    | 01    | RD | 11010  | RS | RT |   OK   | addinc rd, rs, rt |
| and       | 01    | RD | 00010  | RS | RT |   OK   | and rd, rs, rt    |
| andnota   | 01    | RD | 01010  | RS | RT |   OK   | andnota rd, rs, rt|
| nand      | 01    | RD | 00011  | RS | RT |   OK   | nand rd, rs, rt   |
| nor       | 01    | RD | 00101  | RS | RT |   OK   | nor rd, rs, rt    |
| ornotb    | 01    | RD | 01011  | RS | RT |   OK   | ornotb rd, rs, rt |
| sub       | 01    | RD | 11001  | RS | RT |   OK   | sub rd, rs, rt    |
| subdec    | 01    | RD | 11011  | RS | RT |   OK   | subdec rd, rs, rt |
| xnor      | 01    | RD | 00111  | RS | RT |   OK   | xnor rd, rs, rt   |
| xor       | 01    | RD | 00110  | RS | RT |   OK   | xor rd, rs, rt    |
| or        | 01    | RD | 00100  | RS | RT |   OK   | or rd, rs, rt     |
| asl       | 01    | RD | 10001  | RS | RT |   OK   | asl rd, rs        |
| asr       | 01    | RD | 10011  | RS | RT |   OK   | asr rd, rs        |
| deca      | 01    | RD | 11101  | RS | RT |   OK   | deca rd, rs       |
| inca      | 01    | RD | 11100  | RS | RT |   OK   | inca rd, rs       |
| lsl       | 01    | RD | 10000  | RS | RT |        | lsl rd, rs        |
| lsr       | 01    | RD | 10010  | RS | RT |        | lsr rd, rs        |
| passa     | 01    | RD | 01001  | RS | RT |   OK   | passa rd, rs      |
| passnota  | 01    | RD | 01000  | RS | RT |   OK   | passnota rd, rs  |
| zeros     | 01    | RD | 00000  | -  | -  |   OK   | zeros rd          |
| ones      | 01    | RD | 00001  | RS | RT |   OK   | ones rd           |

### Tipo 2
| Instrução | OpCode | Rd | Offset11     | Status | Formato             |
|:---------:|:------:|:--:|:------------:|:------:|:-------------------:|
| loadlit   |   10   | RD | 00000000000  |   OK   | loadlit rd, 11bits  |

### Tipo 3
| Instrução | Opcode | Rd | R   | Offset8  | Status | Formato       |
|:---------:|:-----:|:--:|:---:|:--------:|:------:|:--------------:|
| lcl       | 11    | RD | 0   | 00000000 |   OK   | lcl rd, 8bits  |
| lch       | 11    | RD | 1   | 00000000 |   OK   | lch rd, 8bits  |

### Tipo 4
| Instrução | Opcode | Funct | Cond   | Offset8  | Status | Formato      |
|:---------:|:------:|:-----:|:------:|:--------:|:------:|:-------------:|
| jf.cond   | 00     | 00    | 0000   | 00000000 |        | jf.cond 8bits |
| jt.cond   | 00     | 01    | 0000   | 00000000 |        | jt.conf 8bits |

### Tipo 5
| Instrução | Opcode | OP | Offset12      | Status | Formato     |
|:---------:|:-----:|:--:|:-------------:|:------:|:------------:|
| j         | 00    | 10 | 000000000000  |        | j 12bits     |

### Tipo 6
| Instrução | Opcode | OP | R | X | Rt | Status | Formato       |
|:---------:|:------:|:--:|:-:|:-:|:--:|:------:|:--------------:|
| jal       | 00     | 11 | 0 | - | RT |        | jal rt         |
| jr        | 00     | 11 | 1 | - | RT |        | jr rt          |

### Tipo 7
| Instrução | Opcode | Rd | OP    | Rs | Rt | Status | Formato      |
|:---------:|:-----:|:--:|:-----:|:--:|:--:|:------:|:-------------:|
| load      | 01    | RD | 10100 | RS | RT |        | load rd, rs   |
| store     | 01    | RD | 10110 | RS | RT |        | store rs, rt  |
