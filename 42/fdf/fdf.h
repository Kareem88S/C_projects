
#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include <stdint.h>
# include <sys/types.h>
# include <sys/uio.h>

# include "libft.h" 


enum e_control_things
{
	READ_LINE_ERROR = -3,
	MEMORY_FAIL = -2,
	WRONG_INPUT = -1,
	FDF_SUCCESS = 0,
	STD_OUT = 1,
	MAX_SIZE_MAP = 10000;
};

typedef struct s_landscape
{
	size_t	x_axis_len;
	size_t	y_axis_len;
	int		**altitude;
}	t_landscape;

// read functions
int		read_fdf_file(int fd, t_landscape *data);
char	*get_next_line(int fd);
int		*ft_split_ints(char const *s, char c, t_landscape *data);

// helper functions
char	*ft_strchr(const char *s, int c);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);


// error messages
int		error_msg(int error);

#endif