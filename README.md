# Emulador de MIPS 32 bits
Emulador do processador MIPS de 32 bits para a disciplina GCC117 - Arquitetura de Computadores.

[![Build Status](https://travis-ci.org/mathnogueira/mips.svg?branch=master)](https://travis-ci.org/mathnogueira/mips)

## Estrutura do projeto
* emulador
    * build ---> Pasta onde tudo é compilado
    * include ---> headers do emulador
    * libs ---> Dependencias externas do emulador
    * src  ---> Código fonte do emulador
    * tests ---> Testes unitários do emulador
    * CMakeLists.txt ---> Regras de build do projeto

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
