/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 01:14:38 by kasherif          #+#    #+#             */
/*   Updated: 2025/06/23 21:21:29 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

int	get_perc(int data_chunk, int stack_size)
{
	int	result;

	if (stack_size == 0 || data_chunk == 0)
		return (0);
	result = (100 * data_chunk + (stack_size / 2)) / stack_size;
	return (result);
}

t_n	**get_stack_top(t_ctr *tcon, t_stack stack)
{
	if (stack == STACK_A)
		return (&(tcon->a_top));
	return (&(tcon->b_top));
}

/*
Returns the absolute value.
If the value is MIN_INT, the return would be undefined. In the context of this
	program, the use of this function will never reach that size.
Hence, the function returns MAX_INT, although the result is one-off.
*/
int	abs_value(int value)
{
	if (value <= MIN_INT)
		return (MAX_INT);
	if (value < 0)
		return (-value);
	return (value);
}

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

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dest == NULL || destsize == 0)
		return (src_len);
	i = 0;
	while (i < destsize -1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
