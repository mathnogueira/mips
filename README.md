# Emulador de MIPS 32 bits
Emulador do processador MIPS de 32 bits para a disciplina GCC117 - Arquitetura de Computadores.

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
