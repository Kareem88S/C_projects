/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:53:48 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/30 00:03:13 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Copy memory area.
Copies n bytes from memory area src to memory area dest. 
	If dest and src overlap, behavior is undefined. 
	Applications in which dest and src might overlap should use memove instead.
Returns the original value of dest.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d_ptr;
	const unsigned char	*s_ptr;

	if (n == 0 || (!dest && !src))
		return (dest);
	d_ptr = (unsigned char *) dest;
	s_ptr = (const unsigned char *) src;
	while (n--)
	{
		*d_ptr++ = *s_ptr++;
	}
	return (dest);
}

//
// Optimized below
// #include <stdint.h> // For uintptr_t

// void *ft_memcpy_optimized(void *dest, const void *src, size_t n)
// {
//     unsigned long *d_ptr = (unsigned long *) dest; 
// 					// Word-sized pointers (4 or 8 bytes)
//     const unsigned long *s_ptr = (const unsigned long *) src;

// no safeguards if dest or src are NULL ...

//     // Copy word-sized chunks (either 4 or 8 bytes depending on system)
//     while (n >= sizeof(unsigned long))
//     {
//         *d_ptr++ = *s_ptr++;
//         n -= sizeof(unsigned long);  
// 					// Reduce n by the size of the word copied
//     }

//     // Copy any remaining bytes 
// 	   //(since n may not be a multiple of the word size)
//     unsigned char *d_byte = (unsigned char *) d_ptr;
//     const unsigned char *s_byte = (const unsigned char *) s_ptr;
//     while (n--)
//     {
//         *d_byte++ = *s_byte++;
//     }

//     return dest;
// }
