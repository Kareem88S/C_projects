
#include "fdf.h"

int		read_fdf_file(int fd, t_landscape *data);
int		error_msg(int error);
char	*ft_strchr(const char *s, int c);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

		
	// call_read fn
	// call parse fn
	// call store in mem fn
	// call graphic fn
	// call print/play-loop fn

int	main(int argc, char *argv[])
{
	int			fd;
	int			result;
	// struct	struct;
	
	if (argc != 2)
		return (error_msg(WRONG_INPUT)); // Input_error
	fd = open_and_validate_fd(argv[1], &result);
	if (result != GOOD)
		return (-1);
	return (0);
}

int	open_and_validate_fd(char *file_name, int *result) // struct)
{
	// char		*temp;
	// t_landscape	data;
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (read(fd, NULL, 0) == -1)
	{
		*result = WRONG_INPUT;
		return (error_msg(WRONG_INPUT));
	}
	temp = ft_strchr(file_name[1], '.');
	if (*(temp + 1) != 'f' || *(temp + 2) != 'd' || *(temp + 3) != 'f')
	{
		*result = WRONG_INPUT;
		return (error_msg(WRONG_INPUT));
	}


	if (fd < 0)
	{
		perror("Error opening file");
		return (EXIT_FAILURE);
	}
	result = read_fdf_file(fd, &data);
	if (result < 0)
		return (result);
	return (FDF_SUCCESS);
}

int	read_fdf_file(int fd, t_landscape *data)
{
	char	*line;
	int 	*reeks;

	line = malloc(sizeof(char) * MAX_SIZE_MAP);
	if (line == NULL)
		line = malloc(sizeof(char) * (MAX_SIZE_MAP / 5));
	if (line == NULL)
		line = malloc(sizeof(char) * (MAX_SIZE_MAP / 50));
	if (line == NULL)
		return (error_msg(MEMORY_FAIL));
	
	// // read first line
	// line = get_next_line(fd);
	// if (!line)
	// 	return (error_msg(READ_LINE_ERROR));
	reeks = ft_split_ints(line, ' ', data);
	if (reeks == NULL)
		return(error_msg(MEMORY_FAIL));

			// char	**ft_split_ints(char const *s, char c, t_landscape *data)
}

int	error_msg(int error)
{
	if (error == WRONG_INPUT)
	{
		ft_putstr_fd("Usage: './fdf name.fdf'", STD_OUT);
		return (WRONG_INPUT);
	}
	if (error == READ_LINE_ERROR)
	{
		ft_putstr_fd("Failed to read line", STD_OUT);
		return (READ_LINE_ERROR);
	}
	if (error == MEMORY_FAIL)
	{
		ft_putstr_fd("Insufficient memory available", STD_OUT);
		return (MEMORY_FAIL);
	}
	
}

// Locate character in string.
// Returns a pointer to the FIRST occurrence of the character c in the string s.
char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;

	chr = (unsigned char) c;
	while (*s)
	{
		if (*s == chr)
			return ((char *) s);
		s++;
	}
	if (chr == '\0')
		return ((char *) s);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	write(fd, s, ft_strlen(s));
	return ;
}
