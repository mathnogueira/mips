# Emulador de MIPS 16 bits
Emulador do processador MIPS de 16 bits para a disciplina GCC117 - Arquitetura de Computadores.

[![Build Status](https://travis-ci.org/mathnogueira/mips.svg?branch=master)](https://travis-ci.org/mathnogueira/mips)

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
| Instrução | Funct | Rd | OPCode | Rs | Rt | Status | Formato           |
|:---------:|:-----:|:--:|:------:|:--:|:--:|:------:|:-----------------:|
| add       | 01    | RD | 11000  | RS | RT |        | add rd, rs, rt    |
| addinc    | 01    | RD | 11010  | RS | RT |        | addinc rd, rs, rt |
| and       | 01    | RD | 00010  | RS | RT |        | and rd, rs, rt    |
| andnota   | 01    | RD | 01010  | RS | RT |   OK   | andnota rd, rs, rt|
| addinc    | 01    | RD | 11010  | RS | RT |        | addinc rd, rs, rt |
| nand      | 01    | RD | 00011  | RS | RT |   OK   | nand rd, rs, rt   |
| nor       | 01    | RD | 00101  | RS | RT |        | nor rd, rs, rt    |
| ornotb    | 01    | RD | 01011  | RS | RT |        | ornotb rd, rs, rt |
| addinc    | 01    | RD | 11010  | RS | RT |        | addinc rd, rs, rt |
| sub       | 01    | RD | 11001  | RS | RT |        | sub rd, rs, rt    |
| subdec    | 01    | RD | 11011  | RS | RT |        | subdec rd, rs, rt |
| xnor      | 01    | RD | 00111  | RS | RT |   OK   | xnor rd, rs, rt   |
| xor       | 01    | RD | 00110  | RS | RT |        | xor rd, rs, rt    |
| or        | 01    | RD | 00100  | RS | RT |        | or rd, rs, rt     |
| asl       | 01    | RD | 10001  | RS | RT |        | asl rd, rs        |
| asr       | 01    | RD | 10011  | RS | RT |        | asr rd, rs        |
| deca      | 01    | RD | 11101  | RS | RT |        | deca rd, rs       |
| inca      | 01    | RD | 11100  | RS | RT |        | inca rd, rs       |
| lsl       | 01    | RD | 10000  | RS | RT |        | lsl rd, rs        |
| lsr       | 01    | RD | 10010  | RS | RT |        | lsr rd, rs        |
| passa     | 01    | RD | 01001  | RS | RT |   OK   | passa rd, rs      |
| passnota  | 01    | RD | 01000  | RS | RT |        | passanota rd, rs  |
| zeros     | 01    | RD | 00000  | -  | -  |   OK   | zeros rd          |
| ones      | 01    | RD | 00001  | RS | RT |   OK   | ones rd           |

### Tipo 2
| Instrução | Rd | Offset11     | Status | Formato             |
|:---------:|:--:|:------------:|:------:|:-------------------:|
| loadlit   | RD | 00000000000  |   OK   | loadlit rd, 11bits  |

### Tipo 3
| Instrução | Funct | Rd | R   | Offset8  | Status | Formato        |
|:---------:|:-----:|:--:|:---:|:--------:|:------:|:--------------:|
| lcl       | 11    | RD | 0   | 00000000 |   OK   | lcl rd, 8bits  |
| lch       | 11    | RD | 1   | 00000000 |   OK   | lch rd, 8bits  |

### Tipo 4
| Instrução | Funct | OP | Cond   | Offset8  | Status | Formato       |
|:---------:|:-----:|:--:|:------:|:--------:|:------:|:-------------:|
| jf.cond   | 00    | 00 | 0000   | 00000000 |        | jf.cond 8bits |
| jt.cond   | 01    | 00 | 0000   | 00000000 |        | jt.conf 8bits |

### Tipo 5
| Instrução | Funct | OP | Offset12      | Status | Formato      |
|:---------:|:-----:|:--:|:-------------:|:------:|:------------:|
| j         | 00    | 00 | 000000000000  |        | j 12bits     |

### Tipo 6
| Instrução | Funct | OP | R | X | Rt | Status | Formato        |
|:---------:|:-----:|:--:|:-:|:-:|:--:|:------:|:--------------:|
| jal       | 00    | 11 | 0 | - | RT |        | jal rt         |
| jr        | 00    | 11 | 1 | - | RT |        | jr rt          |

### Tipo 7
| Instrução | Funct | Rd | OP    | Rs | Rt | Status | Formato       |
|:---------:|:-----:|:--:|:-----:|:--:|:--:|:------:|:-------------:|
| load      | 01    | RD | 10100 | RS | RT |        | load rd, rs   |
| store     | 01    | RD | 10110 | RS | RT |        | store rs, rt  |
