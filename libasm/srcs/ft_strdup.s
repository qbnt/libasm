bits 64
extern _ft_strlen
extern _malloc
extern _ft_strcpy
section .text
	global _ft_strdup
	_ft_strdup:
	; arg 1 -> rdi
		push	rdi

		call	_ft_strlen

		inc		rax
		mov		rdi, rax
		call	_malloc

		pop		rsi
		mov		rdi, rax
		call	_ft_strcpy

		mov rax, rdi
		ret