/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   least_significant_bit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:59:39 by kasherif          #+#    #+#             */
/*   Updated: 2025/05/14 00:40:02 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	least_significant_bit(int nbr);
char	most_significant_bit(int nbr);
char	even_odd_checker(int nbr);

int	main(void)
{
	signed char	num;
	// int	lsb;
	// int	msb;

	num = 18;	// 0b 0001 0010
	num = 17;	// 0b 0001 0001
	num = -2;	// 0b 1111 1111
	// num = -0;	// 0b 1111 1111
	// lsb = least_significant_bit(num);
	// msb = most_significant_bit(num);
	// printf("%i\n", msb);
	if (!num)
		printf("zero\n");
	else if (even_odd_checker(num) == 1)
		printf("odd\n");
	else
		printf("even\n");
}

char	least_significant_bit(int nbr)
{
	return (nbr & 0b1);
}

char	most_significant_bit(int nbr)
{

	if (nbr & (1 << 7))
		return (1);
	return (0);
}

/*
returns 1 if nbr == odd
returns 2 if nbr == even
*/
char	even_odd_checker(int nbr)
{
	if (nbr & 0b1)
		return (1);
	return (2);
}