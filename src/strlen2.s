[BITS 64]
	global func:strlen
	extern printf
	section .text

loop:
	; --> byte[string + eax] -> first index of the string -- read the byte at string + eax
	cmp byte[rax + rcx], 0
	jz end_strlen
	inc rcx
	jnz loop
	ret

strlen:
	push rbp
	xor rcx, rcx
	mov rbp, rsp		; copy the stack pointer onto rbp
	mov rax, [rdi - 8]		; get the first argument passed in the main function
	jmp loop
	call end_strlen
	syscall
	ret

end_strlen:
	xor rdi, rdi
	xor rsi, rsi
	mov rdi, d
	mov rsi, rcx
	call printf

	mov rsp, rbp		; copy the updated rbp in rsp
	pop rbp			; suppress updated rbp to clean it up
	xor rdi, rdi		; clean the first argument
	xor rsi, rsi
	mov rax, rcx
	;;syscall			; call the function initialized above
	ret			; end of function
;; main:
;; 	push string 		; first argument
;; 	call strlen		; call the function strlen
;; 	mov rax, 60		; initialize the number of syscall "exit" in rax
;; 	syscall			; call exit
	
;; 	ret			; end of function
;; 	section .rodata
	d db '%d', 0Ah, 0
;; 	string db 'Hello World', 0Ah, 0 ; initialize string
