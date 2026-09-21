# binary
BIN_NAME = so_long

# Directories
DIR_HEADER_FILES = header_files
DIR_MLX42 = ../../../MLX42
OBJ_ROOT = obj
DIR_SRC = src
# Nested source directories
DIR_PROG_CORE = $(DIR_SRC)/core
DIR_ENGINE = $(DIR_SRC)/engine
DIR_RENDER = $(DIR_SRC)/render
DIR_SCENES = $(DIR_SRC)/scenes
# Nested game specific
DIR_SOLONG = $(DIR_SCENES)/so_long
DIR_MENU = $(DIR_SCENES)/menu

# Compiler, Includes, and flags
CC = gcc
INCLUDES = -I $(DIR_HEADER_FILES) -I $(DIR_MLX42)/include
DEBUG_FLAG = -g3
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) $(DEBUG_FLAG)
# Linker flags for MLX42
LDFLAGS = -L$(DIR_MLX42)/build -lmlx42 -ldl -lglfw -pthread -lm

# source files
ROOT_SOURCES = $(DIR_SRC)/main.c
CORE = $(DIR_PROG_CORE)/core.c
ENGINE = \
	$(DIR_ENGINE)/life_cycle.c \
	$(DIR_ENGINE)/window.c \
	$(DIR_ENGINE)/loop.c \
	$(DIR_ENGINE)/error.c
RENDER = \
	$(DIR_RENDER)/color.c \
	$(DIR_RENDER)/fill_canvas.c \
	$(DIR_RENDER)/draw_rect.c
SCENES = MENU SO_LONG
MENU = \
	$(DIR_MENU)/menu_init.c \
	$(DIR_MENU)/menu_draw.c \
	$(DIR_MENU)/menu_update.c
# SO_LONG = TBC

# Source file variables
SOURCE_FILES = \
	$(ROOT_SOURCES) $(CORE) $(RENDER) \
	$(ENGINE) $(SCENES)

# Convert .c files to .o files with corresponding directories in OBJ_DIR
OBJECT_FILES = $(patsubst $(DIR_SRC)/%.c, $(OBJ_ROOT)/%.o, $(SOURCE_FILES))
#			patsubst :
#			$(patsubst pattern,replacement,text)
#			pattern → The pattern to match (e.g., %.c).
#			replacement → What to replace the pattern with (e.g., %.o).
#			text → The list of words (filenames) where the pattern is applied.
OBJ_DIRS = $(sort $(dir $(OBJECT_FILES)))
#			dir function and sort function:
#			dir → extracts only the directory portion of each file in the list.
#			sort → removes duplicates and sorts alphabetically.

all: libmlx $(BIN_NAME)

# $(BIN_NAME) :
# 	@echo "Building $@"

libmlx:
	@cmake $(DIR_MLX42) -B $(DIR_MLX42)/build && make -C $(DIR_MLX42)/build -j4

$(BIN_NAME) : libmlx $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o $(BIN_NAME) $(LDFLAGS)

$(OBJECT_FILES): | $(OBJ_DIRS)
#			$|: == order-only prerequisite
#			Now object files will not be (re)build if they already exist.

$(OBJ_DIRS):
	mkdir -p $@
#			-p flag ensures it is only built if dir does not yet exist

$(OBJ_ROOT)/%.o: $(DIR_SRC)/%.c | $(OBJ_DIRS)
	@echo "Building $@" 
	$(CC) $(CFLAGS) -c -o $@ $<
# -c doesn't link, compiles
# -o names
# $@ current target

clean :
	@rm -rf $(DIR_MLX42)/build
	rm -rf $(OBJECT_FILES) $(OBJ_ROOT)
#	@rm -rf $(OBJECT_FILES) $(OBJECT_DIRS) @ == silencer. Command is executed, but commandline doesnt print

fclean: clean
	rm -f $(BIN_NAME)

re: fclean all

#	.PHONY indicates phony targets -- just in case a file named clean(.c) would exist in this directory
.PHONY : all clean fclean re libmlx