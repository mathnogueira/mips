LOOP:
add r0, r3, r1
sub r0, r0, r1
jf.overflow r0 r4 r0
j LOOP

EXIT:
