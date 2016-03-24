[BITS 64]
	section .text
	global putstr:function
	extern write
	extern strlen
putstr:
	test rdi, rdi
	jz retu
	call strlen wrt ..got
	mov rsi, rdi
	mov rdi, 1
	mov rdx, rax
	call write wrt ..plt
retu:
	ret
