bits 64

%define SYS_WRITE 0x2000004
extern ___error

section .text
	global _ft_write

	_ft_write:
		mov         rax, SYS_WRITE
		syscall
		jc          .error
		ret
	.error:
		mov         r15, rax
		call        ___error
		mov         [rax], r15
		mov         rax, -1
		ret