[BITS 64]
	global my_strstr
	section .text

att_str:
	mov rax, rdx		; set the return value to the adress of the first occurence
	leave
	ret

check_al:
	cmp al, 0		; check if the first argument's char == '\0'
	jz att_str		; if true, then jump
	cmp r9, 0		; check if r9 == 0
	jnz att_str		; if false, then jmp
	mov rax, rdi		; else, set the return value to the address of the first arg's first char
	leave
	ret

end:
	cmp bl, 0		; check if the second argument's char == '\0'
	jz check_al		; if true, then jump
	mov rax, 0		; else, return value = NULL
	leave			; set the stack pointer to its initial value (rsp)
	ret			; end of function

wrong:
	xor rcx, rcx		; re-initialize rcx so we can save the first occurence next turn
	xor rdx, rdx		; re-initialize rdx so there is not save anymore
	mov rsi, r8		; re-initialize rsi so we can access the address of the first char
	inc rdi			; still incrementing the address of the first argument
	add r9, 1		; set the value of r9 at 1 for the last check
	jmp loop		; jmp

save_first:
	mov rdx, rdi		; save the address of the first occurence
	add rcx, 1		; increment rcx so the next turn won't save the address again

inc_second:
	cmp rcx, 0		; if rcx == 0
	jz save_first		; save the address of the character
	inc rdi			; inc the address of rdi
	inc rsi			; inc the address of rsi
	add r9, 1		; set the value of r9 at 1 for the last check
	jmp loop		; re-jump in loop

loop:
	mov al, byte[rdi]	; store the char of the first argument in al
	mov bl, byte[rsi]	; store the char in the second argument in bl

	cmp bl, 0		; check if bl == '\0'
	jz end			; jmp
	cmp al, 0		; check if al == '\0'
	jz end			; jmp
	cmp al, bl		; check if al == bl
	je inc_second		; jmp
	jne wrong		; else jmp

my_strstr:
	push rbp		; push the register
	mov rbp, rsp		; rbp is the new stack pointer

	mov r8, rsi		; store the second argument in r8

	xor rdx, rdx
	xor rcx, rcx
	xor r9, r9

	jmp loop
