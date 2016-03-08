[BITS 64]
	global my_rindex:function
	section .text

end:
	mov rax, rdx		; return value = saved value
	leave
	ret

store_addr:
	xor rdx, rdx		; initialize rdx at 0
	mov rdx, rdi		; put the address of rdi in rdx in order to save the occurence
	inc rdi			; increment the address of rdi
	jmp loop		; re-jmp on loop

loop:
	mov bl, byte[rdi]	; initialize the 8-bit register with the first arg's char

	mov cl, sil		; initialize the 8-bit register with the 8-bit value of rsi

	cmp bl, 0		; compare if bl == '\0'
	jz end			; if true, then jmp
	cmp cl, 0		; else if cl == '\0'
	jz end			; if true, then jmp
	cmp bl, cl		; else if bl == cl
	je store_addr		; jmp to save the address

	inc rdi			; increment the address of the first argument
	jmp loop

my_rindex:
	push rbp
	mov rbp, rsp

	xor bl, bl
	xor cl, cl
	xor rax, rax
	xor rdx, rdx

	jmp loop
