/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:50:27 by kasherif          #+#    #+#             */
/*   Updated: 2025/02/09 22:50:27 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_additions.h"

size_t			st_putnbr_base_fd(long n, const char *base, int fd);
size_t			st_putnbr_base_unsigned_fd(unsigned long n,
					const char *base, int fd);
static size_t	validate_and_count(const char *base);
static size_t	putnbr_recursive(unsigned long n,
					const char *base, size_t base_len, int fd);

/*
Validates input, incl base input
Determines base len. Examples: 
	- binary base of "12" is of len 2, which is minimum.
	- octa base of "12345678" is of len 8.
	- custom base of "poneyvif" is of len 8.
		*See C04 - Ex04 (ft_putnbr_base)
Calls putnbr
*/
size_t	st_putnbr_base_fd(long n, const char *base, int fd)
{
	size_t			len;
	size_t			base_len;
	unsigned long	uns_n;

	if (!base || fd < 0)
		return (0);
	base_len = validate_and_count(base);
	if (base_len == 0)
		return (0);
	len = 0;
	if (n < 0)
	{
		len = 1;
		write(fd, "-", 1);
		uns_n = (unsigned long)(-1 * (n + 1) + 1);
	}
	else
		uns_n = (unsigned long) n;
	len += putnbr_recursive(uns_n, base, base_len, fd);
	return (len);
}

size_t	st_putnbr_base_unsigned_fd(unsigned long n, const char *base, int fd)
{
	size_t			len;
	size_t			base_len;

	if (!base || fd < 0)
		return (0);
	base_len = validate_and_count(base);
	if (base_len == 0)
		return (0);
	len = putnbr_recursive(n, base, base_len, fd);
	return (len);
}

/*
Validate the base
- Can be no duplicate chars
- no symbols (+ or -)
- at least two chars
Returns true (1) or false (0)
*/
static size_t	validate_and_count(const char *base)
{
	size_t	i;
	size_t	base_len;

	base_len = 0;
	i = 0;
	while (base[base_len] != '\0')
	{
		if (base[base_len] == '+' || base[base_len] == '-')
			return (0);
		i = 0;
		while (i < base_len)
			if (base[base_len] == base[i++])
				return (0);
		base_len++;
	}
	if (base_len < 2)
		return (0);
	return (base_len);
}

static size_t	putnbr_recursive(unsigned long n, const char *base,
					size_t base_len, int fd)
{
	size_t	len;
	char	c;

	len = 0;
	if (n >= base_len)
		len += putnbr_recursive(n / base_len, base, base_len, fd);
	c = base[n % base_len];
	write(fd, &c, 1);
	len++;
	return (len);
}
