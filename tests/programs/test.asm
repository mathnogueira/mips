; teste de comentário
ones r1 ; Ola
ones r3
zeros r2
TESTE:
add r0, r1, r2
add r0, r0, r0
loadlit r0 2047
add r0, r0, r0
add r0, r0, r0
add r0, r0, r0
add r0, r0, r0
add r0, r0, r0
j TESTE

inca r0

L:  j L
