NAME = libft.a

FT_PRINTF_DIR = src/ft_printf
GNL_DIR = src/gnl
NEW_DIR = src/new
ORIG_DIR = src/orig
INCLUDE_DIR = include

FT_PRINTF_SRC = \
	$(FT_PRINTF_DIR)/ft_printf.c
GNL_SRC = \
	$(GNL_DIR)/get_next_line_utils.c $(GNL_DIR)/get_next_line.c
NEW_SRC = \
	$(NEW_DIR)/ft_strcspn.c $(NEW_DIR)/st_putchar_fd.c $(NEW_DIR)/st_putstr_fd.c $(NEW_DIR)/st_putnbr_base_fd.c \
	$(NEW_DIR)/ft_atoll.c
ORIG_SRC = \
	$(ORIG_DIR)/ft_atoi.c $(ORIG_DIR)/ft_bzero.c $(ORIG_DIR)/ft_calloc.c $(ORIG_DIR)/ft_isalnum.c $(ORIG_DIR)/ft_isalpha.c \ 
	$(ORIG_DIR)/ft_isascii.c $(ORIG_DIR)/ft_isdigit.c $(ORIG_DIR)/ft_isprint.c $(ORIG_DIR)/ft_itoa.c $(ORIG_DIR)/ft_memchr.c \
	$(ORIG_DIR)/ft_memcmp.c $(ORIG_DIR)/ft_memcpy.c $(ORIG_DIR)/ft_memmove.c $(ORIG_DIR)/ft_memset.c $(ORIG_DIR)/ft_putchar_fd.c \
	$(ORIG_DIR)/ft_putendl_fd.c $(ORIG_DIR)/ft_putnbr_fd.c $(ORIG_DIR)/ft_putstr_fd.c $(ORIG_DIR)/ft_split.c $(ORIG_DIR)/ft_strchr.c \
	$(ORIG_DIR)/ft_strdup.c $(ORIG_DIR)/ft_striteri.c $(ORIG_DIR)/ft_strjoin.c $(ORIG_DIR)/ft_strlcat.c $(ORIG_DIR)/ft_strlcpy.c \
	$(ORIG_DIR)/ft_strlen.c $(ORIG_DIR)/ft_strmapi.c $(ORIG_DIR)/ft_strncmp.c $(ORIG_DIR)/ft_strnstr.c $(ORIG_DIR)/ft_strrchr.c \
	$(ORIG_DIR)/ft_strtrim.c $(ORIG_DIR)/ft_substr.c $(ORIG_DIR)/ft_tolower.c $(ORIG_DIR)/ft_toupper.c $(ORIG_DIR)/ft_lstnew.c \
	$(ORIG_DIR)/ft_lstadd_front.c $(ORIG_DIR)/ft_lstsize.c $(ORIG_DIR)/ft_lstlast.c $(ORIG_DIR)/ft_lstadd_back.c \
	$(ORIG_DIR)/ft_lstdelone.c $(ORIG_DIR)/ft_lstclear.c $(ORIG_DIR)/ft_lstiter.c $(ORIG_DIR)/ft_lstmap.c 


SOURCES = $(FT_PRINTF_SRC) $(GNL_SRC) $(NEW_DIR) $(ORIG_SRC) 

OBJECTS = $(SOURCES:.c=.o)

CC = cc 
CFLAGS = -Wall -Wextra -Werror 
DEBUG_FLAG = -g
DEBUG_FLAGS = $(CFLAGS) $(DEBUG_FLAG)

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $@ $^
# ar == archiver tool in Unix/Linux, -- used to create and maintain archives (like .a files).
# rcs == flags passed to ar
#		r: Replaces or adds files to the archive.
#		c: Creates the archive if it does not already exist.
#		s: Creates an index (symbol table) for the archive, making it easier to link.

# Rule to compile individual source files
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean :
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

#	.PHONY indicates clean is a phony target -- just in case a file named clean(.c) would exist in this directory
.PHONY : clean fclean re