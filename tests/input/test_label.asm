LOOP:
	addi $s0 $s0 $s0
	bne $s0 $s1 $s0
		j LOOP

FINISH:
