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
Creation of node for chunk of (final) line
or
Removal of chunk-node-linked-list chain.
If malloc-call fails, result is switched to 'GNL_FAIL' and returns NULL
Else returns ptr to newly created and set node
*/
int	create_rm_chunk_node(t_chunk **node_p, int *result, int mission)
{
	t_chunk	*temp;
	int		i;

	if (mission == GNL_CREATE)
	{
		temp = (t_chunk *) malloc(sizeof(t_chunk));
		if (!temp)
			return (*result = GNL_FAIL);
		i = 0;
		while (i < BUFFER_SIZE)
			temp->buffer[i++] = 0;
		temp->buffer[i] = '\0';
		temp->chunk_size = 0;
		temp->next = NULL;
		(*node_p) = temp;
		return (*result = GNL_SUCCESS);
	}
	while (*node_p)
	{
		temp = (*node_p)->next;
		free(*node_p);
		*node_p = temp;
	}
	return (*result);
}

/*
If newline if found, the function places the remnants in starage for 
the next GNL call.
*/
int	find_and_process_newline(t_fdn *fd_n, t_chunk *current)
{
	size_t	nl_index;

	nl_index = 0;
	while (nl_index < current->chunk_size && current->buffer[nl_index] != '\n')
		nl_index++;
	if (current->buffer[nl_index] != '\n')
		return (GNL_NOT_FOUND);
	fd_n->store_len = current->chunk_size - (nl_index + 1);
	if (fd_n->store_len > 0)
	{
		fd_n->store = malloc(sizeof(char) * fd_n->store_len + 1);
		if (!fd_n->store)
			return (GNL_FAIL);
		ft_memcpy(fd_n->store, &current->buffer[nl_index + 1], fd_n->store_len);
		fd_n->store[fd_n->store_len] = '\0';
	}
	else
		fd_n->store = NULL;
	current->chunk_size = (nl_index + 1);
	fd_n->total_line_len -= fd_n->store_len;
	return (GNL_FOUND);
}

/*
Fill buffer with remnants of previous call if needed. 
 Can be max of size BUFFER_SIZE - 1 (because \n in prev call).
 After copying, the storage-space is freed.
Else fills buffer from read-call and adds '\0' to string.
 Fails if read failed or (final) line grows beyond GNL_MAX_LINE_LENGTH (1MB)
Then the newline char is searched for.
*/
int	fill_chunk(t_fdn *fd_n, t_chunk *chunk, int bytes_read)
{
	if (fd_n->store_len > 0)
	{
		ft_memcpy(chunk->buffer, fd_n->store, fd_n->store_len);
		chunk->chunk_size = fd_n->store_len;
		fd_n->total_line_len = fd_n->store_len;
		fd_n->store_len = 0;
		free (fd_n->store);
		fd_n->store = NULL;
	}
	else
	{
		bytes_read = read(fd_n->n_fd, chunk->buffer, BUFFER_SIZE);
		if (bytes_read < 0 || bytes_read > BUFFER_SIZE)
			return (GNL_FAIL);
		if (bytes_read == 0)
			return (GNL_EOF);
		chunk->buffer[bytes_read] = '\0';
		chunk->chunk_size = bytes_read;
		fd_n->total_line_len += bytes_read;
		if (fd_n->total_line_len > GNL_MAX_LINE_LENGTH)
			return (GNL_FAIL);
	}
	if (GNL_FOUND == find_and_process_newline(fd_n, chunk))
		return (GNL_FOUND);
	return (GNL_NOT_FOUND);
}

/*
Is only called if all else went well. Then allocates memory for the final line,
 and copies the buffers (from various chunks) into newly allocd returnable line
Returns the char* on success and NULL if malloc fails.
*/
char	*finalize_line(int *result, t_fdn *fdn, t_chunk *head)
{
	char	*final_line;
	char	*current_pos;

	final_line = malloc(sizeof(char) * fdn->total_line_len + 1);
	if (!final_line)
		return ((*result = GNL_FAIL), NULL);
	current_pos = final_line;
	while (head)
	{
		ft_memcpy(current_pos, head->buffer, head->chunk_size);
		fdn->total_line_len -= head->chunk_size;
		current_pos += head->chunk_size;
		head = head->next;
	}
	*current_pos = '\0';
	return (final_line);
}

/*
Copies str in chunks. 
If str > minimum-size chunk
	copies whole chunks
else
	copies per byte
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long		*d_ptr;
	const unsigned long	*s_ptr;
	unsigned char		*d_byte;
	const unsigned char	*s_byte;

	s_ptr = (const unsigned long *) src;
	d_ptr = (unsigned long *) dest;
	while (n >= sizeof(unsigned long))
	{
		*d_ptr++ = *s_ptr++;
		n -= sizeof(unsigned long);
	}
	d_byte = (unsigned char *) d_ptr;
	s_byte = (const unsigned char *) s_ptr;
	while (n--)
		*d_byte++ = *s_byte++;
	return (dest);
}
