LIBRARY = libftprintf.a

HEADER = libftprintf.h

PRINTF_SOURCES = ft_printf.c
HELPER_SOURCES = ft_strchr.c st_putnbr_base_fd.c st_putchar_fd.c st_putstr_fd.c
SOURCES = $(PRINTF_SOURCES) $(HELPER_SOURCES)

OBJECTS = $(SOURCES:.c=.o)

CC = cc 
CFLAGS = -Wall -Wextra -Werror 
CFLAGS_DEBUG = -Wall -Wextra -Werror -g
DEBUG_EXEC = ./debug
# Compiler and flags

all : $(LIBRARY)
# Targets

$(LIBRARY) : $(OBJECTS)
	ar rcs $@ $^
# ar == archiver tool in Unix/Linux, 
#		used to create and maintain archives (like .a files).
# rcs == flags passed to ar
#		r: Replaces or adds files to the archive.
#		c: Creates the archive if it does not already exist.
#		s: Creates an index (symbol table) for the archive, making it easier to link.
# Reference commands below ($@ and $^). Refer to earlier mentioned.
# $@ Makefile automatic variable. 
# 	Expands to the target name. In this case:
#		$(NAME) -- which expands to libftprintf.a
# $^ Makefile automatic variable. 
#	Expands to the list of all prerequisites (dependencies) of the target:
#		$(OBJECTS) 


debug: $(OBJECTS)
	$(CC) $(CFLAGS_DEBUG) $(OBJECTS) -o $(DEBUG_EXEC)

clean:
	rm -f $(OBJECTS) $(DEBUG_EXEC) test_program

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re debug
#	.PHONY indicates clean (or otherwise named as above) is a phony target 
#		-- just in case a file named clean(.c) would exist in this directory




# test_program: test_file.c libftprintf.a
# 	$(CC) $(CFLAGS_DEBUG) test_file.c -L. -lftprintf -o test_program
# clean:
# 	rm -f $(OBJECTS) $(DEBUG_EXEC) test_program
