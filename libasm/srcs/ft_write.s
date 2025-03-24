bits 64

%define STD_WRITE 0x2000004

section .text
	global _ft_write
	_ft_write:
		mov rax, STD_WRITE
		syscall
		ret