bits 64

section .text
	global _ft_strcpy
	_ft_strcpy:
		xor rcx, rcx
	.loop:
		movzx rax, byte [rsi + rcx]
		mov [rdi + rcx], al
		test al, al
		je .done
		inc rcx
		jmp .loop

	.done:
		mov rax, rdi
		ret