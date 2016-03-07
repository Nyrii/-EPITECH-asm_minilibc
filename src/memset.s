[BITS 64]
	section .text
	global my_memset
my_memset:
	xor rcx, rcx			; i = 0
	jmp check
loop:
	mov [rdi + rcx], rsi	 	; ((char *)ptr)[i] = c
	inc rcx				; i++
check:
	cmp rdx, rcx			; if (i < n)
	jle end
	jmp loop
end:
	mov rax, rdi			; return (ptr)
	ret
