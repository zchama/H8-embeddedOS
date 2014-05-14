	.h8300h
	.section .text
	.global _start
_start:
	mov.1	#0xffff00,sp
	jsr	@_main
1:
	bra	1b
