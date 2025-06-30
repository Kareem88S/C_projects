/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightrot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:49:29 by kasherif          #+#    #+#             */
/*   Updated: 2025/05/15 19:07:00 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned rightrot(unsigned x, int n);

/*
rotates the bits of x by n positions.
returns new value of x.

Psuedo:
	store the rightmost n bits.
	rotate x >> n
	place the stored-rightmost bits in place of leftmost.
*/
unsigned rightrot(unsigned x, int n)
{
	unsigned	temp;
	const char	size = sizeof(x) * 8;

	temp = x & (~(~0 << n));
	temp = temp << (size - n);
	x = (x >> n) | temp;
	return (x);
}

int main(void)
{
	unsigned	x;
	int			n;

	x = 0b10011100;
	n = 3;
	// expected rexult
	// x == 0b 1001 0011
	x = rightrot(x, n);
	return (0);
}