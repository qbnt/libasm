# Libasm

Libasm is a project from 42 school that consists in rewriting basic C library functions in x86_64 assembly to deepen understanding of low-level programming.

## Description

The goal of this project is to re-implement a few standard C library functions in NASM assembly language for the x86_64 architecture, and to understand how they work internally.

## Functions Implemented

- `ft_strlen`   – Calculate the length of a string
- `ft_strcpy`   – Copy a string to another
- `ft_strcmp`   – Compare two strings
- `ft_write`    – Write to a file descriptor
- `ft_read`     – Read from a file descriptor
- `ft_strdup`   – Duplicate a string

## Bonus Functions (if applicable)

You may also implement additional functions to go further:

- `ft_atoi`     – Convert a string to an integer
- `ft_strchr`   – Locate a character in a string
- `ft_strrchr`  – Locate last occurrence of a character in a string

## Requirements

- NASM (Netwide Assembler)
- GCC (or Clang) for compiling and linking with your assembly

## Usage

To compile the assembly functions:

```bash
nasm -f elf64 ft_strlen.s
nasm -f elf64 ft_strcpy.s
# etc.
```

To test with a C file:

```bash
gcc -no-pie main.c ft_strlen.o ft_strcpy.o -o libasm_test
./libasm_test
```

## Testing

You can write your own C test files or use a testing framework such as:

- [libasm-tester](https://github.com/jtoty/LibasmTester)
- [libasm_unit_test](https://github.com/0x050f/libasm_unit_test)

## Author

Quentin Banet

## License

This project is part of the 42 curriculum and is intended for educational purposes.
