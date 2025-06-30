/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:38:08 by kasherif          #+#    #+#             */
/*   Updated: 2025/02/11 02:06:49 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "../libft.h"

/*
Size-bounded string concatenation: appends string src to the end of dst.
take the full size of the destination buffer and guarantee NUL-termination 
	if there is room. Note that room for the NUL should be included in dstsize.
Both src and dst must be NUL-terminated.
Append at most dstsize - strlen(dst) - 1 characters.
If the src and dst strings overlap, the behavior is undefinded.
Returns the total length of the string it tried to create.
If the return value is >= dstsize, 
	the output string has been truncated. (Caller's responsibility).
dst_len == original (first part) of concatination -- destsize == both strings
*/
size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (destsize <= dest_len)
		return (src_len + destsize);
	i = dest_len;
	j = 0;
	while (src[j] != '\0' && i < destsize - 1)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (src_len + dest_len);
}
