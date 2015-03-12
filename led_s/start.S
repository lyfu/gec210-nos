.globl _start

_start:
	ldr r1, =0xE0200280 					
	ldr r0, =0x00001111
	str r0, [r1]

	mov r2, #0x1000
led_blink:
	ldr r1, =0xE0200284 					
	mov r0, #0
	str r0, [r1]

	bl delay							

	ldr r1, =0xE0200284 					
	mov r0, #0xf
	str r0, [r1]

	bl delay	

	sub r2, r2, #1
	cmp r2,#0
	bne led_blink


halt:
	b halt


delay:
	mov r0, #0x100000
delay_loop:
	cmp r0, #0
	sub r0, r0, #1
	bne delay_loop
	mov pc, lr

