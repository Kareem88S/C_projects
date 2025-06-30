/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:00:21 by kasherif          #+#    #+#             */
/*   Updated: 2024/11/15 02:27:57 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <stdio.h>

# define GNL_MAX_LINE_LENGTH 1000000	// 1mb

# ifndef MAX_FDS
#  define MAX_FDS 1250  		// Max file descriptors active simultaniously
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16 		// Default buffer size
# elif BUFFER_SIZE > 1000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1000000	// 2mb
# endif

enum e_action_constants
{
	GNL_EOF = 0,
	GNL_FAIL = -1,
	GNL_SUCCESS = 100,
	GNL_NOT_FOUND = -777,
	GNL_FOUND = 777,
	GNL_CREATE = 1,
	GNL_RM = -2,
	GNL_DUMMY
}	; // values generally arbitrary

// struct for read-nodes
typedef struct s_chunk_node
{
	char				buffer[BUFFER_SIZE + 1];	// str data, \0-terminated
	size_t				chunk_size;					// valid bytes in buffer
	struct s_chunk_node	*next;						// Ptr next chunk in L-List
}	t_chunk;

// struct for fd-node
typedef struct s_static_fd_node
{
	int		n_fd;			// this node's fd
	size_t	total_line_len;	// accumulated chars in all node-chunks (excl \0)
	char	*store;			// ptr to remainder from previous call
	int		store_len;		// incl all read-nodes, no 0-term
	t_chunk	*head;			// head_node, in case linked list
}	t_fdn;

char	*get_next_line(int fd);
t_fdn	*create_fdn(int fd, t_fdn **fd_node, int *result);
char	*build_line(t_fdn *fd_n, t_chunk **cur_ptr, int *result);
char	*finalize_line(int *result, t_fdn *fdn, t_chunk *head);
char	*remove_fdn(t_fdn **fd_n, char *final_line, int result);
int		create_rm_chunk_node(t_chunk **node_p, int *result, int mission);
int		find_and_process_newline(t_fdn *fd_n, t_chunk *current);
int		fill_chunk(t_fdn *fd_n, t_chunk *chunk, int bytes_read);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif

/*
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16 			// Default buffer size
# elif BUFFER_SIZE > 5000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
*/