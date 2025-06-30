/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:04:35 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/23 15:04:35 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "../libft.h"

static const char	*skip_whitespaces(const char *nptr);
static const char	*check_sign(const char *nptr, int *sign);

/*
converts ascii to int
converts the initial portion of the string pointed to by nptr to int.
***does not detect errors***
may begin with an arbitrary number of whitespaces as determined by isspace(3)
				\t => tabulation
				\n => new line
				\v => vertical tabulation
				\f => form feed
				\r => carriage return
				' ' => space
After the arbitrary number of whitespaces, 
	there can be !!_ONE_!! single optional '+' or '-' sign
The remainder of the string will be converted to an int, 
	stopping at the first character which is not a valid digit in the given base 
	(in our case we only need to manage base 10, so the valid digits are 0-9) 
Not handling under- or overflow.. As instructed	
*/
int	ft_atoi(const char *nptr)
{
	int	sign;
	int	outcome;

	nptr = skip_whitespaces(nptr);
	nptr = check_sign(nptr, &sign);
	outcome = 0;
	while (ft_isdigit(*nptr))
	{
		outcome *= 10;
		outcome += *nptr - '0';
		nptr++;
	}
	return (outcome * sign);
}

static const char	*skip_whitespaces(const char *nptr)
{
	while (*nptr == '\t' || *nptr == '\n' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r' || *nptr == ' ')
	{
		nptr++;
	}
	return (nptr);
}

static const char	*check_sign(const char *nptr, int *sign)
{
	*sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			*sign *= -1;
		nptr++;
	}
	return (nptr);
}
