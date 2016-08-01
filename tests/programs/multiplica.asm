	.module m0

; Programa MULTIPLICA.ASM
; Este programa multiplica dois valores de ate 11 bits
; POSITIVOS, armazenados em r0 e r1. O resultado eh 
; armazenado em Mem[1000]
;
;
	.pseg
	loadlit r0,50 		; Operando A
	loadlit r1,5 		; Operando B
	zeros r2

LOOP:	add r2,r2,r1
	deca r0,r0
	jf.zero LOOP
	loadlit r1,1000
	store r1,r2		; armazena o produto AxB em Mem[1000]

HALT:	j HALT
	.end
