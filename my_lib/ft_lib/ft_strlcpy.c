/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:19:21 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/28 02:28:01 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Size-bounded string copying.
Takes the full size of the destination buffer and guarantee NUL-termination 
	if there is room. Note that room for the NUL should be included in dstsize.
Src must be NUL-terminated.
copies up to dstsize - 1 characters from the string src to dst, 
	NUL-terminating the result if dstsize is not 0.
If the src and dst strings overlap, the behavior is undefined.
No safeguard: if dst or src is NULL: segfault!
Returns the total length of the strings it tried to create. 
	That means the length of src.
If the return value is >= dstsize, 
	the output string has been truncated. (caller'sresponsibility).
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (dest == NULL || destsize == 0)
		return (src_len);
	while (i < destsize -1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
