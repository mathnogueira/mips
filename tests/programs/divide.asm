; Programa DIVIDE.ASM
; Este programa divide um numero inteiro de ate 16 bits por outro
; tambem de 16 bits e armazena o resultado em Mem[1000]

	lcl r2, 1500		; Divisor
	lch r2, 1500
	lcl r3, 5		; Dividendo
	lch r3, 5
	zeros r4

LOOP:   sub r2,r2,r3
    ;    jt.neg SAIDA
	inca r4,r4
	j LOOP

SAIDA: 	loadlit r3,1000
	store r3,r4
