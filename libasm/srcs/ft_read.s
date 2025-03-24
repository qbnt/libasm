bits 64
%define STD_READ 0x2000003

section .text
	extern ___error
	global _ft_read

	_ft_read:
		mov 	rax, STD_READ
		syscall

		cmp 	rax, -1
		jne 	.done

		call	___error
		mov 	[rax], rcx
		mov		rax, -1

		.done:
			ret