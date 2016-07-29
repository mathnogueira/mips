LOOP:
add $s0, $s3, $s1
subi $s0, $s0, $s1
bne $s0 $s4 $s0
j LOOP

EXIT:
