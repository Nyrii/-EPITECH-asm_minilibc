[BITS 64]
	global func:_my_strlen
	;; extern printf
	section .text

_my_strlen:
	push rbp		;
	mov rbp, rsp		; create temporary stack

	mov rax, [rbp - 8]
	xor rcx, rcx

	test rax, 0   		; set ZF to 1 if rax == 0
	je ret 			; jump if ZF ==1

	cmp	rax, 0
	jne	loop
loop:
	inc rcx
	cmp byte [rax + rcx], 0
	jne loop

ret:
	mov rsp, rbp		;
	pop rbp			; delete temporary stack
	mov rax, rcx
	mov rax, 42

	ret

;; hello:
;; 	push rbp		;
;; 	mov rbp, rsp		; create temporary stack

;; 	mov rdi, FormatStr	;
;; 	mov rax, 0		; push printf args
;; 	call printf wrt ..plt

;; 	mov rsp, rbp		;
;; 	pop rbp			; delete temporary stack

;; 	mov rax, 42		;
;; 	ret			; return (42)

;; main:
;; 	push rbp		;
;; 	mov rbp, rsp		; create temporary stack

;; 	sub rsp, 16		; create int

;; 	mov rax, 0		; arg
;; 	call hello

;; 	;; push String
;; 	;; mov rdi, FormatStr	; arg
;; 	;; mov rax, 0		; arg
;; 	;; call strlen

;; 	;; Both these line are useless here
;; 	mov [rbp - 4], rax	; get return value in int
;; 	mov rax, [rbp - 4]	; put int back in rax

;; 	mov rsi, rax		;
;; 	mov rdi, FormatStr2	;
;; 	mov rax, 1		; push printf args
;; 	call printf wrt ..plt

;; 	mov rsp, rbp		;
;; 	pop rbp			; delete temporary stack

;; 	mov rax, 60		;
;; 	xor rdi, rdi		;
;; 	syscall			; exit(0)

;; 	ret

;; 	section .rodata

	String		db "Tamer la pute"
	FormatStr	db "Hello World !",0Ah,0
	FormatStr2	db "%d",0Ah,0
