/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftrot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:07:49 by kasherif          #+#    #+#             */
/*   Updated: 2025/05/15 19:18:25 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned leftrot(unsigned x, int n);

/*
rotates the bits of x by n positions.
returns new value of x.

Psuedo:
	store the leftmost n bits.
	rotate x << n
	place the stored-leftmost bits in place of rightmost.
*/
unsigned leftrot(unsigned x, int n)
{
	const char	size = sizeof(x) * 8;
	unsigned	temp;

	temp = (x & ((~(~0 << n)) << (size - n))) >> (size - n);
	x = (x << n) | temp;
	return (x);
}

int	main(void)
{
	unsigned int	x;
	char			n;

	x = 0b00111100;
	n = 2;
	x = leftrot(x, n);
	return (0);
}