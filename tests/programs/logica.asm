	.module m0

; Programa LOGICA.ASM
; Este programa testa todas as operacoes logicas da ALU
; Cada teste incrementa o registrador r4 se for bem sucedido.
; no final, se todos os testes forem bem sucedidos, a pontuacao
; atinge valor 10, que eh armazenada em Mem[1000]
; Cada teste verifica se a tabela verdade para a operacao
; esta sendo gerada corretamente.

	.pseg	
        zeros r4
        
teste0:
	zeros r0		; Operacao C = A & B;
	zeros r1		
	and r1,r0,r1
	jf.zero teste1
	zeros r0
	ones r1		
	and r1,r0,r1
	jf.zero teste1
	ones r0
	zeros r1		
	and r1,r0,r1
	jf.zero teste1
	ones r0
	ones r1		
	and r1,r0,r1
        passnota r1,r1
	jf.zero teste1
	inca r4,r4

teste1:	
	zeros r0		; Operacao C = !A & B
	zeros r1		
	andnota r1,r0,r1        	
	jf.zero teste2
	zeros r0
	ones r1		
	andnota r1,r0,r1
        passnota r1,r1
	jf.zero teste2
	ones r0
	zeros r1		
	andnota r1,r0,r1
	jf.zero teste2
	ones r0
	ones r1		
	andnota r1,r0,r1
	jf.zero teste2
	inca r4,r4

teste2: 
	zeros r0		; Operacao C = A		
	passa r1,r0
	jf.zero teste3
	ones r0		
 	passa r1,r0
        passnota r1,r0
	jf.zero teste3
	inca r4,r4

teste3:	
	zeros r0		; Operacao C = A ^ B
	zeros r1		
	xor r1,r0,r1
	jf.zero teste4
	zeros r0
	ones r1		
	xor r1,r0,r1
 	passnota r1,r1
	jf.zero teste4
	ones r0
	zeros r1		
	xor r1,r0,r1
 	passnota r1,r1
	jf.zero teste4
	ones r0
	ones r1		
	xor r1,r0,r1
	jf.zero teste4
	inca r4,r4

teste4:	
	zeros r0		; Operacao C = A | B
	zeros r1		
	or r1,r0,r1
	jf.zero teste5
	zeros r0
	ones r1		
	or r1,r0,r1
 	passnota r1,r1
	jf.zero teste5
	ones r0
	zeros r1		
	or r1,r0,r1
 	passnota r1,r1
	jf.zero teste5
	ones r0
	ones r1		
	or r1,r0,r1
        passnota r1,r1
	jf.zero teste5
	inca r4,r4

teste5:	
	zeros r0		; Operacao C = !A & !B
	zeros r1		
	nor r1,r0,r1
 	passnota r1,r1
	jf.zero teste6
	zeros r0
	ones r1		
	nor r1,r0,r1
	jf.zero teste6
	ones r0
	zeros r1		
	nor r1,r0,r1
	jf.zero teste6
	ones r0
	ones r1		
	nor r1,r0,r1
	jf.zero teste6
	inca r4,r4

teste6:	
	zeros r0		; Operacao C = !A ^ B
	zeros r1		
	xnor r1,r0,r1
 	passnota r1,r1
	jf.zero teste7
	zeros r0
	ones r1		
	xnor r1,r0,r1
	jf.zero teste7
	ones r0
	zeros r1		
	xnor r1,r0,r1
	jf.zero teste7
	ones r0
	ones r1		
	xnor r1,r0,r1
 	passnota r1,r1
	jf.zero teste7
	inca r4,r4

teste7:	
	zeros r0		; Operacao C = !A		
	passnota r0,r0
        passnota r0,r0
	jf.zero teste8
	ones r0		
 	passnota r0,r0
	jf.zero teste8
	inca r4,r4

teste8:
	zeros r0		; Operacao C = A | !B
	zeros r1		
	ornotb r1,r0,r1
 	passnota r1,r1
	jf.zero teste9
	zeros r0
	ones r1		
	ornotb r1,r0,r1
	jf.zero teste9
	ones r0
	zeros r1		
	ornotb r1,r0,r1
 	passnota r1,r1
	jf.zero teste9
	ones r0
	ones r1		
	ornotb r1,r0,r1
        passnota r1,r1
	jf.zero teste9
	inca r4,r4

teste9:	
	zeros r0		; Operacao C = !A | !B
	zeros r1		
	nand r1,r0,r1
        passnota r1,r1
	jf.zero result
	zeros r0
	ones r1		
	nand r1,r0,r1
 	passnota r1,r1
	jf.zero result
	ones r0
	zeros r1		
	nand r1,r0,r1
 	passnota r1,r1
	jf.zero result
	ones r0
	ones r1		
	nand r1,r0,r1
	jf.zero result
	inca r4,r4

result: loadlit r0, 1000
	store r0,r4
	
	HALT:   j HALT

	.end
