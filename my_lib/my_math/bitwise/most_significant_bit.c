/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   most_significant_bit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:06:32 by kasherif          #+#    #+#             */
/*   Updated: 2025/05/14 14:06:35 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	most_significant_bit(int nbr);

int	main(void)
{
	int	msb;

	// num = 18;	// 0b 0001 0010
	// num = 17;	// 0b 0001 0001
	num = -2;	// 0b 1111 1111
	msb = most_significant_bit(num);
	printf("%i\n", msb);
	return (0);
}

/*
option 1: get exact size of variable (bits)
Casts nbr to unsigned and the operation on 1 is also cast to U, 
	ensuring well-defined behaviour (considering the sign-bit). 
*/
char	most_significant_bit(int nbr)
{
	char	bits;
	
	bits = (sizeof(nbr) * 8);
	if ((unsigned)nbr & (1U << (bits - 1)))
		return (1);
	return (0);

}

// /*
// option 2: cast to unsigned char (byte)
// This is a very limited option, only useful in cases of 8-bits (chars only)
// */
// char	most_significant_bit(int nbr)
// {
// 	unsigned char	byte;
	
// 	byte = (unsigned char) nbr;
// 	if (nbr & (1 << 7))
// 		return (1);
// 	return (0);
// }
