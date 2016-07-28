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
| Instrução | Funct | Rd | OPCode | Rs | Rt |
| ----------|-------|----|--------|----|----|
| add       | 01    | rd | 11000  | rs | rt |
| addinc    | 01    | rd | 11010  | rs | rt |
| and       | 01    | rd | 00010  | rs | rt |
| andnota   | 01    | rd | 01010  | rs | rt |
| asl       | 01    | rd | 10001  | rs | rt |
| asr       | 01    | rd | 10011  | rs | rt |
| deca      | 01    | rd | 11101  | rs | rt |
| inca      | 01    | rd | 11100  | rs | rt |
| addinc    | 01    | rd | 11010  | rs | rt |
| lsl       | 01    | rd | 10000  | rs | rt |
| lsr       | 01    | rd | 10010  | rs | rt |
| nand      | 01    | rd | 00011  | rs | rt |
| nor       | 01    | rd | 00101  | rs | rt |
| ones      | 01    | rd | 00001  | rs | rt |
| or        | 01    | rd | 00100  | rs | rt |
| ornotb    | 01    | rd | 01011  | rs | rt |
| passa     | 01    | rd | 01001  | rs | rt |
| passnota  | 01    | rd | 01000  | rs | rt |
| addinc    | 01    | rd | 11010  | rs | rt |
| sub       | 01    | rd | 11001  | rs | rt |
| subdec    | 01    | rd | 11011  | rs | rt |
| xnor      | 01    | rd | 00111  | rs | rt |
| xor       | 01    | rd | 00110  | rs | rt |

### Tipo 2
- loadlit

### Tipo 3
- lcl

### Tipo 4
- jf.cond
- jt.cond

### Tipo 5
- j

### Tipo 6
- jal
- jr

### Tipo 7
- load
- store
