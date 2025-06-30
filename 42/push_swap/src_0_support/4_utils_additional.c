/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_utils_additional.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 01:14:38 by kasherif          #+#    #+#             */
/*   Updated: 2025/06/17 22:42:10 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

#include <stdint.h>

/*
memory for an array of nmemb elements of size bytes each and
returns a pointer to the allocated memory.  The memory is set to zero.
If size is 0, then malloc() returns either
NULL or a unique pointer value (to be freed later)
If the multiplication of nmemb and size would result in integer overflow,
then calloc() returns an  error
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mem_ptr;
	size_t			memory_size_request;

	if (nmemb == 0 || size == 0 || (nmemb > (MAX_LONG / size)))
		return (NULL);
	memory_size_request = nmemb * size;
	if (memory_size_request / size != nmemb)
		return (NULL);
	mem_ptr = malloc(memory_size_request);
	if (mem_ptr == NULL)
		return (NULL);
	ft_bzero(mem_ptr, memory_size_request);
	return (mem_ptr);
}

/*
Write zeroes to a byte string.
writes n zeroed bytes to the string s. If n is zero, bzero() does nothing.
*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (n--)
		*ptr++ = 0;
}
