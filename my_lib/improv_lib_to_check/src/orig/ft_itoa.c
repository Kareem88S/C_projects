/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:04:24 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/27 16:04:24 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "../libft.h"

static void		fill_string(int n, size_t strlen, char *string);
static size_t	count_digits(int n);

/*
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
returns the string representing n; NULL if the memory allocation failed.
MIN_INT == -2147483648
*/
char	*ft_itoa(int n)
{
	size_t	strlen;
	char	*string;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == 0)
	{
		string = (char *) malloc((1 + 1) * sizeof(char));
		if (string == NULL)
			return (NULL);
		string[0] = '0';
		string[1] = '\0';
		return (string);
	}
	strlen = count_digits(n);
	if (n < 0)
		strlen++;
	string = malloc((strlen + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	fill_string(n, strlen, string);
	return (string);
}

static void	fill_string(int n, size_t strlen, char *string)
{
	if (n < 0)
	{
		string[0] = '-';
		n = -n;
	}
	string[strlen] = '\0';
	while (strlen > 0 && n != 0)
	{
		strlen--;
		string[strlen] = (n % 10) + '0';
		n = n / 10;
	}
}

static size_t	count_digits(int n)
{
	if (n < 0)
		n = n * -1;
	if (n <= 9)
		return (1);
	else
		return (1 + count_digits(n / 10));
}
