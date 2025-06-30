/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:01:53 by kasherif          #+#    #+#             */
/*   Updated: 2024/11/14 02:48:48 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
						!!!! Note !!!!
		Change ft_memcpy to gnl_memcpy (or something), or
		remove ft_memcpy and refer to libft.
							!!!!
*/

/*
Checks valid input.
Statically creates fd-structure to store vital data on the current FD.
Then build_line() takes over to handle the FD and assemble the line.
Finally: 
- If the function was a success, the final_line was created and the 
	linked list of read-chunks is freed, before returning the line.
- If EOF, then the FD-node is also removed.
- If FAIL, then line is also removed and returns NULL
*/
char	*get_next_line(int fd)
{
	static t_fdn	*fd_node[MAX_FDS];
	t_fdn			*fd_n;
	int				result;
	char			*final_line;

	result = GNL_SUCCESS;
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= MAX_FDS)
		return ((result = GNL_FAIL), NULL);
	if (fd_node[fd])
		fd_n = fd_node[fd];
	else
		fd_n = create_fdn(fd, &fd_node[fd], &result);
	if (fd_n == NULL || result == GNL_FAIL)
		return ((result = GNL_FAIL), NULL);
	final_line = build_line(fd_n, &(fd_n->head), &result);
	if (result == GNL_FAIL || result == GNL_EOF)
	{
		(void) remove_fdn(&fd_node[fd], final_line, result);
		return (final_line);
	}
	(void) create_rm_chunk_node(&fd_n->head, &result, GNL_RM);
	return (final_line);
}

/*
'current_node' is initially set to the location of head (chunk-node) via
	cur_ptr, which was given the address to the head-node.
First, space is allocated for the content for new read-nodes (initially head).
Then static memory is checked for remaining chars from previous calls.
If present, 'from_storage_to_buf' handles and empties the stored chars
	stores it in buffer of first 'chunk-node', AKA head, and
	the 'head->next' node to be the new 'current'. 
	ALso looks for \n or EOF
From then on out, read takes over:
	If read fails, return NULL to kill process (free all later)
	At EOF with nothing read, same as above
	At EOF with filled buffer, 'finalize_line' takes over and finishes
	Otherwise, looking for '\n'
if no '\n', new read-node is malloced to store (from read) next line-chunk.
*/
char	*build_line(t_fdn *fd_n, t_chunk **cur_ptr, int *result)
{
	t_chunk	*current_chunk;

	while (*result == GNL_SUCCESS || *result == GNL_NOT_FOUND)
	{
		if (fd_n->store_len > 0 && (!fd_n->store || fd_n->store[0] == '\0'))
			return ((*result = GNL_FAIL), NULL);
		if (GNL_FAIL == create_rm_chunk_node(cur_ptr, result, GNL_CREATE))
			return ((*result = GNL_FAIL), NULL);
		current_chunk = *cur_ptr;
		*result = fill_chunk(fd_n, current_chunk, GNL_DUMMY);
		if (*result == GNL_FOUND)
			return (finalize_line(result, fd_n, fd_n->head));
		if (*result == GNL_EOF && fd_n->total_line_len > 0)
			return (finalize_line(result, fd_n, fd_n->head));
		cur_ptr = &(current_chunk->next);
	}
	return (NULL);
}

/*
Takes as arg the address of the corresponding FD node and allocates space.
If successfull, sets the fields.
Returns the address of the new node or NULL on fail
*/
t_fdn	*create_fdn(int fd, t_fdn **fd_n, int *result)
{
	*fd_n = malloc(sizeof(t_fdn));
	if (*fd_n == NULL)
		return ((*result = GNL_FAIL), NULL);
	(*fd_n)->n_fd = fd;
	(*fd_n)->total_line_len = 0;
	(*fd_n)->store = NULL;
	(*fd_n)->store_len = 0;
	(*fd_n)->head = NULL;
	return (*fd_n);
}

/*
Deletes the node corresponding to the given file descriptor.
Frees any potential remains of earlier calls and sets .store to NULL.
Frees linked list of chunks (read-nodes) and sets the head to NULL.
Frees the FD node and sets its address to NULL, indicating availability.
In case of FAIL, also frees and NULLs any allocated final_line char* space.
*/
char	*remove_fdn(t_fdn **fd_n, char *final_line, int result)
{
	size_t	i;

	if ((*fd_n)->store)
	{
		i = 0;
		while (i < (size_t)(*fd_n)->store_len)
			(*fd_n)->store[i++] = '\0';
		free ((*fd_n)->store);
	}
	(*fd_n)->store = NULL;
	(void) create_rm_chunk_node(&(*fd_n)->head, &result, GNL_RM);
	(*fd_n)->head = NULL;
	(*fd_n)->n_fd = -1;
	(*fd_n)->store_len = 0;
	(*fd_n)->total_line_len = 0;
	free(*fd_n);
	*fd_n = NULL;
	if (result == GNL_FAIL)
	{
		if (final_line)
			free (final_line);
		final_line = NULL;
	}
	return (final_line);
}
