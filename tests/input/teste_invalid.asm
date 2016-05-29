LOOP:
add $s0, $zero, $t0
subi $s0, $s0, 1
bne $s0 $zero EXIT
j LOOP

EXIT:
