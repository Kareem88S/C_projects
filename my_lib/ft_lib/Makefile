NAME = libft.a
SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
NEWLY_ADDED_FUNCTIONS_SRC = free_and_null.c

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
NEW_OBJ = $(NEWLY_ADDED_FUNCTIONS_SRC:.c=.o)

CC = cc 
CFLAGS = -Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : $(OBJECTS) $(BONUS_OBJ) $(NEW_OBJ)
	ar rcs $@ $^

bonus : $(NAME) $(BONUS)

#	.PHONY indicates clean is a phony target -- just in case a file named clean(.c) would exist in this directory
.PHONY : clean fclean re

clean :
	rm -f $(OBJECTS) $(BONUS_OBJ) $(NEW_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all