.global _start
	
_start:
	mov r0, #0x53
	msr	CPSR_cxsf, r0
	ldr sp, =0x35000000
	b main
