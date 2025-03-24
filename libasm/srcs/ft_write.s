bits 64

%define SYS_WRITE 0x2000004

section .text
	extern ___error
	global _ft_write

	_ft_write:
		mov     rax, SYS_WRITE
		syscall

		cmp     rax, -1
		jne     .done

		call    ___error
		mov     [rax], rcx
		mov     rax, -1

	.done:
		ret