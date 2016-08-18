loadlit r3 5
loadlit r0 1000
loadlit r1 3
START:
store r0 r1
add r0, r0, r0
jt.overflow OK
jal r1
j EXIT
OK:
inca r1
jr r7

EXIT: j EXIT
