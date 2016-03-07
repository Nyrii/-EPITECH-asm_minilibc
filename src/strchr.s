[BITS 64]
	global my_strchr
	section .text

end:
	mov rax, rdi	 	; give to the return value the address of the char (rdi)
	leave			; re-set the stack pointer to its initial ptr
	ret

loop:
	mov al, byte[rdi]	; attribute the char of char * (rdi) to a 8-bit register
	movsx rdx, al		; attribute the value of 8 bit register to a new bigger (64 bits) register (increase size)

	cmp al, 0		; check if the character != '\0'
	jz end			; if true, then end
	cmp rdx, rsi		; check if the character of the first argument == the second argument
	je end			; if true, then end

	inc rdi			; increment the address of the char ptr

	jmp loop		; loop again

my_strchr:
	push rbp		; push the register
	mov rbp, rsp		; put the stack pointer to rbp

	xor rax, rax		; return value = 0

	jmp loop		; loop
