LOOP:
	addi $s0 $s0 -1
	bne $s0 $zero
		j LOOP

FINISH:
