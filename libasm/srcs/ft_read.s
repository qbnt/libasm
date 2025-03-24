bits 64
%define STD_READ 0x2000003
extern ___error

section .text
	global _ft_read

	_ft_read:
		mov 	rax, STD_READ
		syscall
		jc		.error
		ret

	.error:
		mov         r15, rax            ; save errno
		call        ___error            ; retrieve address to errno
		mov         [rax], r15          ; put errno in return value of __error (pointer to errno)
		mov         rax, -1
		ret