[BITS 64]
	section .text
	global my_strlen

my_strlen:
	mov rbx, rdi			; move char * in register
	xor rax, rax			; reinit iterator

loop:
	inc rax
	cmp byte [rbx + rax - 1], 0	; compare with \0
	jz loop				; not equal -> reloop
	dec rax

	ret
