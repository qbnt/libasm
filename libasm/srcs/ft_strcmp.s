bits 64

section .text
	global _ft_strcmp
	_ft_strcmp:
		xor rcx, rcx
		.loop:
			movzx eax, byte [rdi + rcx]
			movzx ebx, byte [rsi + rcx]
			cmp eax, ebx
			jne .diff
			test eax, eax
			je .done
			inc rcx
			jmp .loop

		.diff:
			sub eax, ebx
			ret
		.done:
			xor eax, eax
			ret