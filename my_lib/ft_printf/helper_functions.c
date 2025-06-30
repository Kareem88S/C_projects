/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:39:21 by kasherif          #+#    #+#             */
/*   Updated: 2025/01/02 19:39:21 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return (0);
	write (fd, &c, 1);
	return (1);
}

size_t	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	char	*counter_ptr;

	if (fd < 0)
		return (0);
	if (!s)
		s = "(null)";
	counter_ptr = s;
	len = 0;
	while (*counter_ptr++)
		len++;
	write(fd, s, len);
	return (len);
}

/*
Locate character in string.
Returns a pointer to the FIRST occurrence of the character c in the string s.
*/
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
