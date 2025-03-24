NAME = libasm.a
SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS = $(SRC:.s=.o)
NASM = nasm
NASMFLAGS = -f elf64
AR = ar rcs
RM = rm -f

all: $(NAME)

%.o: srcs/%.s
	$(NASM) $(NASMFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all