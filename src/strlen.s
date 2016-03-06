[BITS 64]
	section .text
	global my_strlen

my_strlen:
	;; push rbp			;
	;; mov rbp, rsp			; create temporary stack

	mov rbx, rdi			; move char * in register
	xor rax, rax			; reinit iterator

loop:
	inc rax
	cmp byte [rbx + rax - 1], 0	; compare with \0
	jne loop			; loop id false
	dec rax

	;; leave				; delete temporary stack
	ret
