# Project = 03_line_improved
NAME = draw_line

# Directories
DIR_SRC = src
DIR_OBJ = obj
DIR_HEADER_FILES = include
DIR_MLX42 = $(HOME)/programming/MLX42

# Compiler and flags
CC = cc
INCLUDES = -I$(DIR_HEADER_FILES) -I$(DIR_MLX42)/include
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
LDFLAGS = -L$(DIR_MLX42)/build
LDLIBS = -lmlx42 -ldl -lglfw -pthread -lm

# Source files
SRC_FILES = $(DIR_SRC)/main.c \
			$(DIR_SRC)/graphics.c \
			$(DIR_SRC)/pixel.c \
			$(DIR_SRC)/line.c \
			$(DIR_SRC)/helper.c

# Object files
OBJ_FILES = $(DIR_OBJ)/main.o \
			$(DIR_OBJ)/graphics.o \
			$(DIR_OBJ)/pixel.o \
			$(DIR_OBJ)/line.o \
			$(DIR_OBJ)/helper.o

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(NAME) $(LDFLAGS) $(LDLIBS)

# Note the |pipe: order-only prerequisite
# changes to obj/ do not force recompilation
$(OBJ_FILES): | $(DIR_OBJ)

$(DIR_OBJ):
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/main.o: $(DIR_SRC)/main.c
	$(CC) $(CFLAGS) -c $(DIR_SRC)/main.c -o $(DIR_OBJ)/main.o
$(DIR_OBJ)/graphics.o: $(DIR_SRC)/graphics.c
	$(CC) $(CFLAGS) -c $(DIR_SRC)/graphics.c -o $(DIR_OBJ)/graphics.o
$(DIR_OBJ)/pixel.o: $(DIR_SRC)/pixel.c
	$(CC) $(CFLAGS) -c $(DIR_SRC)/pixel.c -o $(DIR_OBJ)/pixel.o
$(DIR_OBJ)/line.o: $(DIR_SRC)/line.c
	$(CC) $(CFLAGS) -c $(DIR_SRC)/line.c -o $(DIR_OBJ)/line.o
$(DIR_OBJ)/helper.o: $(DIR_SRC)/helper.c
	$(CC) $(CFLAGS) -c $(DIR_SRC)/helper.c -o $(DIR_OBJ)/helper.o

clean:
	rm -f $(OBJ_FILES)
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re