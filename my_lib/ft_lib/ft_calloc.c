/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:05:05 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/23 15:05:05 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
memory for an array of nmemb elements of size bytes each and
returns a pointer to the allocated memory.  The memory is set to zero.
	--If size is 0, then malloc() returns either 
	--NULL or a unique pointer value (to be freed later)
If the multiplication of nmemb and size would result in integer overflow, 
then calloc() returns an  error
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mem_ptr;
	size_t			memory_size_request;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (SIZE_MAX / size))
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

// int main(void)
// {
// 	int *artwee;
// 	printf("%p\n", artwee);
// 	artwee = ft_calloc(1, sizeof(int));
// 	printf("%p, %i\n", artwee, *artwee);
// }