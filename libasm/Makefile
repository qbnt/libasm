# Variables
NAME        = libasm.a
ASM         = nasm
ASMFLAGS    = -f macho64
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -Iincludes
AR          = ar
ARFLAGS     = rcs

SRC_DIR     = srcs
OBJ_DIR     = objs
TEST_DIR    = tests

# Liste des sources en assembleur
ASM_SRCS    = $(SRC_DIR)/ft_strcmp.s $(SRC_DIR)/ft_write.s $(SRC_DIR)/ft_read.s\
            	$(SRC_DIR)/ft_strcpy.s $(SRC_DIR)/ft_strlen.s

# Transformation des fichiers .s en .o dans le dossier objs
OBJS        = $(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(ASM_SRCS))

# Fichier de test
TEST        = $(TEST_DIR)/test.c
TEST_BIN    = test_bin

# Règles
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s includes/libasm.h | $(OBJ_DIR)
	$(ASM) $(ASMFLAGS) $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compilation de la cible de test
test: $(NAME)
	$(CC) $(CFLAGS) $(TEST) -L. -lasm -o $(TEST_BIN)
	@echo "Exécution du test :"
	./$(TEST_BIN)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(TEST_BIN)

re: fclean all

.PHONY: all clean fclean re test