# binary
BIN_NAME = philosophers

# Directories
HEADER_FILES_DIR = header_files
OBJ_ROOT = obj
SRC_DIR = src
# # Nested source directories
# PROG_CORE_DIR = $(SRC_DIR)/core
# ENGINE_DIR = $(SRC_DIR)/engine
# RENDER_DIR = $(SRC_DIR)/render
# SCENES_DIR = $(SRC_DIR)/scenes
# # Nested game specific
# SOLONG_DIR = $(SCENES_DIR)/so_long
# MENU_DIR = $(SCENES_DIR)/menu

# Compiler, Includes, and flags
CC = gcc
INCLUDES = -I $(HEADER_FILES_DIR)
DEBUG_FLAG = -g3
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) $(DEBUG_FLAG)
# Linker flags for multithreading ????
LDFLAGS = -pthread
AFLAG = -S #assembly code

# source files
ROOT_SOURCES = $(SRC_DIR)/main.c
MEMORY = $(SRC_DIR)/memory_management.c
PREPARATORY = $(SRC_DIR)/validate_input.c $(SRC_DIR)/create_threads.c
ERROR = $(SRC_DIR)/error_handling.c
# CORE = $(PROG_CORE_DIR)/core.c
# ENGINE = \
# 	$(ENGINE_DIR)/life_cycle.c \
# 	$(ENGINE_DIR)/window.c \
# 	$(ENGINE_DIR)/loop.c \
# 	$(ENGINE_DIR)/error.c
# RENDER = \
# 	$(RENDER_DIR)/color.c \
# 	$(RENDER_DIR)/fill_canvas.c \
# 	$(RENDER_DIR)/draw_rect.c
# SCENES = MENU SO_LONG
# MENU = \
# 	$(MENU_DIR)/menu_init.c \
# 	$(MENU_DIR)/menu_draw.c \
# 	$(MENU_DIR)/menu_update.c
# # SO_LONG = TBC

# Source file variables
SOURCE_FILES = \
	$(ROOT_SOURCES) $(MEMORY) $(PREPARATORY) \
 	$(ERROR) 
#	$(SCENES)

# Convert .c files to .o files with corresponding directories in OBJ_DIR
OBJECT_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_ROOT)/%.o, $(SOURCE_FILES))
#			patsubst :
#			$(patsubst pattern,replacement,text)
#			pattern → The pattern to match (e.g., %.c).
#			replacement → What to replace the pattern with (e.g., %.o).
#			text → The list of words (filenames) where the pattern is applied.
OBJ_DIRS = $(sort $(dir $(OBJECT_FILES)))
#			dir function and sort function:
#			dir → extracts only the directory portion of each file in the list.
#			sort → removes duplicates and sorts alphabetically.

all: $(BIN_NAME)

# $(BIN_NAME) :
# 	@echo "Building $@"

$(BIN_NAME) : $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o $(BIN_NAME) $(LDFLAGS)

$(OBJECT_FILES): | $(OBJ_DIRS)
#			$|: == order-only prerequisite
#			Now object files will not be (re)build if they already exist.

$(OBJ_DIRS):
	mkdir -p $@
#			-p flag ensures it is only built if dir does not yet exist

$(OBJ_ROOT)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIRS)
	@echo "Building $@" 
	$(CC) $(CFLAGS) -c -o $@ $<
# -c doesn't link, compiles
# -o names
# $@ current target

clean :
	rm -rf $(OBJECT_FILES) $(OBJ_ROOT)
#	@rm -rf $(OBJECT_FILES) $(OBJECT_DIRS) @ == silencer. Command is executed, but commandline doesnt print

fclean: clean
	rm -f $(BIN_NAME)

re: fclean all

#	.PHONY indicates phony targets -- just in case a file named clean(.c) would exist in this directory
.PHONY : all clean fclean re