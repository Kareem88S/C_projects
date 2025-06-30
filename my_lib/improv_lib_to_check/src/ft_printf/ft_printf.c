/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:07:40 by kasherif          #+#    #+#             */
/*   Updated: 2025/02/11 13:17:32 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strchr(const char *s, int c);
/*
variadic function that accepts arbitrary number of args
Loops through provided string. Prints regular chars 
until specifier is encountered. Then calls handler-function.
Returns chars printed (int)
*/
int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	size_t		chars_printed;
	const char	*allowed_specifiers = "cspdiuxX%";

	va_start(args, fmt);
	if (!fmt)
		return ((errno = EINVAL), PF_INVALID);
	chars_printed = 0;
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			if (ft_strchr(allowed_specifiers, *fmt++) == NULL)
				errno = EINVAL;
			else
				chars_printed += handle_specifiers(args, *fmt, PF_STD_OUT);
		}
		else if (*fmt != '%')
			chars_printed += st_putchar_fd(*fmt, PF_STD_OUT);
		if (errno == EINVAL)
			return ((errno = EINVAL), PF_INVALID);
		fmt++;
	}
	va_end(args);
	return ((int)chars_printed);
}

size_t	handle_specifiers(va_list args, char specifier, int fd)
{
	if (specifier == '%')
		return (st_putchar_fd('%', fd));
	if (specifier == 'c')
		return (st_putchar_fd(va_arg(args, int), fd));
	if (specifier == 's')
		return (st_putstr_fd(va_arg(args, char *), fd));
	if (specifier == 'd' || specifier == 'i')
		return (st_putnbr_base_fd(va_arg(args, int), PF_BASE_DIGIT, fd));
	if (specifier == 'u')
		return (st_putnbr_base_uns_fd(va_arg(args, unsigned int),
				PF_BASE_DIGIT, fd));
	if (specifier == 'X')
		return (st_putnbr_base_uns_fd(va_arg(args, unsigned int), HXUP, fd));
	if (specifier == 'x')
		return (st_putnbr_base_uns_fd(va_arg(args, unsigned int), HXLOW, fd));
	if (specifier == 'p')
		return (handle_ptr(args, fd));
	return (0);
}

size_t	handle_ptr(va_list args, int fd)
{
	size_t	len;
	void	*ptr;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
		return (ft_putstr_fd("(nil)", 1));
	len = st_putstr_fd("0x", 1);
	len += st_putnbr_base_uns_fd((unsigned long)ptr, HXLOW, fd);
	return (len);
}

// /*
// Locate character in string.
// Returns a pointer to the FIRST occurrence of the character c in the string s.
// */
// static char	*ft_strchr(const char *s, int c)
// {
// 	unsigned char	chr;

// 	chr = (unsigned char) c;
// 	while (*s)
// 	{
// 		if (*s == chr)
// 			return ((char *) s);
// 		s++;
// 	}
// 	if (chr == '\0')
// 		return ((char *) s);
// 	return (NULL);
// }

/*
NB
Why EINVAL:
https://sourceware.org/glibc/manual/latest/pdf/libc.pdf p27
https://man7.org/linux/man-pages/man3/errno.3.html
*/