BIN_NAME = push_swap

# Compiler, Includes, and flags
CC = gcc
INCLUDES = -I $(HEADER_FILES_DIR)
DEBUG_FLAG = -g3
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) $(DEBUG_FLAG)

# Directories
OBJECT_DIR = object_files
SOURCE_DIRS = \
	$(HEADER_FILES_DIR) $(SUPPORT) $(MOVE_OPERATIONS_DIR) $(UPDATE_DIR)
# $(PREPARATORY_FILES_DIR) $(SORTING_ALGORITHMS_DIR)

HEADER_FILES_DIR = 			header_files
SUPPORT =					src_0_support
PREPARATORY_FILES_DIR = 	src_1_preps
UPDATE_DIR = 				src_2_update_data
MOVE_OPERATIONS_DIR = 		src_3_move_operations
SORTING_ALGORITHMS_DIR = 	src_4_sorting_algos
# MISC_DIR = 					src_5_misc

# Source file variables
SOURCE_FILES = \
	$(ROOT_SOURCES) \
	$(SUPPORT_FILES) $(PREPARATORY_FILES) $(MOVE_OPERATIONS) \
	$(SORTING_ALGORITHMS) $(UPDATE_DATA)
# $(MISC) 
	

# source files
ROOT_SOURCES = main.c
SUPPORT_FILES = \
	$(SUPPORT)/1_free_functions.c \
	$(SUPPORT)/2_ft_split.c \
	$(SUPPORT)/3_utils.c \
	$(SUPPORT)/4_utils_additional.c \
	$(SUPPORT)/5_normalizing_array.c
# $(SUPPORT)/3_get_extremes.c \
# $(SUPPORT)/2_check_top_swap.c
# $(SUPPORT)/5_build_array.c
PREPARATORY_FILES = \
	$(PREPARATORY_FILES_DIR)/1_controller.c \
	$(PREPARATORY_FILES_DIR)/2_validate_input_parse_into_array.c \
	$(PREPARATORY_FILES_DIR)/3_validate_dups_and_normalize_values.c \
	$(PREPARATORY_FILES_DIR)/4_parse_into_circ_linked_list.c
UPDATE_DATA = \
	$(UPDATE_DIR)/1_updater.c \
	$(UPDATE_DIR)/2_updater_helper.c

# $(UPDATE_DIR)/1_update_global_state.c \
# $(UPDATE_DIR)/1_update_sub_state.c \
# $(UPDATE_DIR)/3_update_tcon_utils_off_and_buckets.c \
# $(UPDATE_DIR)/4_update_sub_stack.c \
# $(UPDATE_DIR)/5_update_sub_stack_utils.c
# 	$(UPDATE_DIR)/1_update_stack_nodes.c \
# 	$(UPDATE_DIR)/4_update_tcon_utils_lss.c \
# 	$(UPDATE_DIR)/6_update_leader_scores_global.c \
# 	$(UPDATE_DIR)/5_update_best_mv.c
# 	$(UPDATE_DIR)/5_update_distance_to_target.c

MOVE_OPERATIONS = \
	$(MOVE_OPERATIONS_DIR)/1_push_operation.c \
	$(MOVE_OPERATIONS_DIR)/2_swap_operation.c \
	$(MOVE_OPERATIONS_DIR)/3_rotate_operation.c \
	$(MOVE_OPERATIONS_DIR)/4_print_operation.c \
	$(MOVE_OPERATIONS_DIR)/5_moving.c
SORTING_ALGORITHMS = \
	$(SORTING_ALGORITHMS_DIR)/1_sorting_manager.c \
	$(SORTING_ALGORITHMS_DIR)/2_mini_sort_base_case.c \
	$(SORTING_ALGORITHMS_DIR)/3_two_three_elements_sorter.c \
	$(SORTING_ALGORITHMS_DIR)/4_four_elements_sorter.c \
	$(SORTING_ALGORITHMS_DIR)/5_five_elements_sorter.c \
	$(SORTING_ALGORITHMS_DIR)/6_two_off.c \
	$(SORTING_ALGORITHMS_DIR)/7_reverse_sort.c \
	$(SORTING_ALGORITHMS_DIR)/8_quick_sort.c \
	$(SORTING_ALGORITHMS_DIR)/9_insertion_sort.c \
	$(SORTING_ALGORITHMS_DIR)/10_bucket_sort.c \
	$(SORTING_ALGORITHMS_DIR)/11_bucket_meta.c \
	$(SORTING_ALGORITHMS_DIR)/12_bucket_distribution.c
	
# $(SORTING_ALGORITHMS_DIR)/13_four_bucket_sort.c 
# $(SORTING_ALGORITHMS_DIR)/9_push_and_return.c \
#	$(SORTING_ALGORITHMS_DIR)/7_insertion_sort.c \


# MISC = \
# 	$(MISC_DIR)/free_all.c \
# 	$(MISC_DIR)/utils.c


# Convert .c files to .o files with corresponding directories in OBJ_DIR
OBJECT_FILES = $(patsubst %.c, $(OBJECT_DIR)/%.o, $(SOURCE_FILES))
#			patsubst :
#			$(patsubst pattern,replacement,text)
#			pattern → The pattern to match (e.g., %.c).
#			replacement → What to replace the pattern with (e.g., %.o).
#			text → The list of words (filenames) where the pattern is applied.
OBJECT_DIRS = $(sort $(dir $(OBJECT_FILES)))
#			dir function and sort function:
#			dir → extracts only the directory portion of each file in the list.
#			sort → removes duplicates and sorts alphabetically.

#	.PHONY indicates phony targets -- just in case a file named clean(.c) would exist in this directory
.PHONY : all clean fclean re

all: $(BIN_NAME)

# $(BIN_NAME) :
# 	@echo "Building $@"

$(BIN_NAME) : $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o $(BIN_NAME)

$(OBJECT_FILES): | $(OBJECT_DIRS)
#			$|: == order-only prerequisite
#			Now object files will not be (re)build if they already exist.

$(OBJECT_DIRS):
	mkdir -p $@
#			-p flag ensures it is only built if dir does not yet exist

$(OBJECT_DIR)/%.o: %.c
	@echo "Building $@" 
	$(CC) $(CFLAGS) -c -o $@ $<
# -c doesn't link, compiles
# -o names
# $@ current target

clean :  
	rm -rf $(OBJECT_FILES) $(OBJECT_DIR)
#	@rm -rf $(OBJECT_FILES) $(OBJECT_DIRS) @ == silencer. Command is executed, but commandline doesnt print

fclean: clean
	rm -f $(BIN_NAME)

re: fclean all