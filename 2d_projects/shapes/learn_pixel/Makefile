# Project = 00_pixel
NAME = learn_pixel

# directories
DIR_MLX42 = $(HOME)/programming/MLX42
DIR_SRC = src
DIR_OBJ = obj

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(DIR_MLX42)/include
LDFLAGS = -L$(DIR_MLX42)/build
LDLIBS = -lmlx42 -ldl -lglfw -pthread -lm

# Source files
SRC_FILES = $(DIR_SRC)/main.c

# Object files
OBJ_FILES = $(DIR_OBJ)/main.o

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(NAME) $(LDFLAGS) $(LDLIBS)

$(DIR_OBJ)/main.o: $(DIR_SRC)/main.c
	$(CC) $(CFLAGS) -c $(DIR_SRC)/main.c -o $(DIR_OBJ)/main.o

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re