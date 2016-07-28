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
| Instrução | Funct | Rd | OPCode | Rs | Rt | Status |
| ----------|-------|----|--------|----|----|--------|
| add       | 01    | RD | 11000  | RS | RT |        |
| addinc    | 01    | RD | 11010  | RS | RT |        |
| and       | 01    | RD | 00010  | RS | RT |        |
| andnota   | 01    | RD | 01010  | RS | RT |        |
| asl       | 01    | RD | 10001  | RS | RT |        |
| asr       | 01    | RD | 10011  | RS | RT |        |
| deca      | 01    | RD | 11101  | RS | RT |        |
| inca      | 01    | RD | 11100  | RS | RT |        |
| addinc    | 01    | RD | 11010  | RS | RT |        |
| lsl       | 01    | RD | 10000  | RS | RT |        |
| lsr       | 01    | RD | 10010  | RS | RT |        |
| nand      | 01    | RD | 00011  | RS | RT |   OK   |
| nor       | 01    | RD | 00101  | RS | RT |        |
| ones      | 01    | RD | 00001  | RS | RT |        |
| or        | 01    | RD | 00100  | RS | RT |        |
| ornotb    | 01    | RD | 01011  | RS | RT |        |
| passa     | 01    | RD | 01001  | RS | RT |   OK   |
| passnota  | 01    | RD | 01000  | RS | RT |        |
| addinc    | 01    | RD | 11010  | RS | RT |        |
| sub       | 01    | RD | 11001  | RS | RT |        |
| subdec    | 01    | RD | 11011  | RS | RT |        |
| xnor      | 01    | RD | 00111  | RS | RT |   OK   |
| xor       | 01    | RD | 00110  | RS | RT |        |
| zeros     | 01    | RD | 00000  | -  | -  |   OK   |

### Tipo 2
| Instrução | Rd | Offset11     | Status |
|-----------|----|--------------|--------|
| loadlit   | RD | 00000000000  |        |

### Tipo 3
| Instrução | Funct | Rd | R   | Offset8  | Status |
| ----------|-------|----|-----|----------|--------|
| lcl       | 11    | RD | bit | 00000000 |        |

### Tipo 4
| Instrução | Funct | OP | Cond   | Offset8  | Status |
|-----------|-------|----|--------|----------|--------|
| jf.cond   | 00    | 00 | 0000   | 00000000 |        |
| jt.cond   | 01    | 00 | 0000   | 00000000 |        |

### Tipo 5
| Instrução | Funct | OP | Offset12      | Status |
|-----------|-------|----|---------------|        |
| j         | 00    | 00 | 000000000000  |        |

### Tipo 6
| Instrução | Funct | OP | R | X | Rt | Status |
|-----------|-------|----|---|---|----|--------|
| jal       | 00    | 11 | 0 | - | RT |        |
| jr        | 00    | 11 | 1 | - | RT |        |

### Tipo 7
| Instrução | Funct | Rd | OP    | Rs | Rt | Status |
|-----------|-------|----|-------|----|----|--------|
| load      | 01    | RD | 10100 | RS | RT |        |
| save      | 01    | RD | 10110 | RS | RT |        |
