	.module m0

; Programa para para testar shift logico a esquerda e a direita
; Desloca a esquerda o numero 0001 ate 8000. Em seguida desloca 
; 8000 a direita ate tornar-se FFFF. Armazena o resultado nas 
; 32 posicoes de memoria consecutivas a partir da posicao 03E8 (1000).
; Executar o programa com dump de memoria de 32 posicoes a partir
; de 03E8.
;
	.pseg
        loadlit r0,1000
	ones r1
L1:	store r0,r1      
	inca r0,r0
	lsl r1,r1
	jf.neg L1
L2:	store r0,r1
	inca r0,r0
	lsr r1,r1
	jf.zero L2
	
; A saida correta devera conter:
;
; Mem[1000] = 1			Mem[1016] = c000
; Mem[1001] = 2		   	Mem[1017] = e000	
; Mem[1002] = 4			Mem[1018] = f000
; Mem[1003] = 8			Mem[1019] = f800 
; Mem[1004] = 10		Mem[1020] = fc00
; Mem[1005] = 20		Mem[1021] = fe00
; Mem[1006] = 40		Mem[1022] = ff00
; Mem[1007] = 80		Mem[1023] = ff80
; Mem[1008] = 100		Mem[1024] = ffc0
; Mem[1009] = 200		Mem[1025] = ffe0
; Mem[1010] = 400		Mem[1026] = fff0
; Mem[1011] = 800		Mem[1027] = fff8
; Mem[1012] = 1000		Mem[1028] = fffc
; Mem[1013] = 2000		Mem[1029] = fffe
; Mem[1014] = 4000		Mem[1030] = ffff
; Mem[1015] = 8000		Mem[1031] = ffff
;	

HALT:	j HALT
	.end
