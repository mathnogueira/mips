loadlit r3 5
loadlit r0 1000
loadlit r1 3
store r0 r1
add r0, r0, r0
jt.overflow OK
jal r1

OK:
inca r1

EXIT: j EXIT
