[BITS 64]
	section .text
	global my_memset:function
my_memset:
	xor rcx, rcx			; i = 0
	jmp check
loop:
	mov byte [rdi + rcx], sil 	; ((char *)ptr)[i] = c
	inc rcx				; i++
check:
	cmp rdx, rcx			; if (i < n)
	jg loop
end:
	mov rax, rdi			; return (ptr)
	ret
