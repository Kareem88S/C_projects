/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:45:50 by kasherif          #+#    #+#             */
/*   Updated: 2025/05/15 18:39:13 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned invert(unsigned x, int p, int n);

/*
Returns x, where the n bits at location p have been inverted (flipped), meaning
all 1s switch to 0s, and all 0s switch to 1s,
leaving all other bits unchanged.

Psuedo:
	creates a mask, where only n @ p are present. 
	Flips x using the mask.
	returns that section to x.
*/
unsigned invert(unsigned x, int p, int n)
{
	unsigned mask;

	mask = (~(~0 << n) << (p - n + 1));
	x = x ^ mask;
	return (x);

}

int main()
{

	unsigned x = 0b11010011;
	int p = 5;
	int n = 4;
	// result = 0b11111111;
	invert(x,p,n);
	// mask == 0011 1100
}
