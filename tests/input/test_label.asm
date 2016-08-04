LOOP:
	add r0 r0 r0
	jf.zero r0 r1 r0
		j LOOP

FINISH:
