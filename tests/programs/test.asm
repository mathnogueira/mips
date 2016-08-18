; teste de comentário
ones r1 ; Ola
ones r3
zeros r2
TEST:
add r0, r1, r2
add r0, r0, r0
loadlit r0 2046
add r0, r0, r0
add r0, r0, r0
add r0, r0, r0
add r0, r0, r0
add r0, r0, r0

jt.negzero TEST

inca r0

L:  j L
