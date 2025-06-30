/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:10:11 by kasherif          #+#    #+#             */
/*   Updated: 2025/05/15 14:31:33 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gets n-bits from position p
*/
unsigned get_bits(unsigned x, int p, int n)
{
	x = x >> (p + 1 - n);	// 0b 0010 0111 
	x = (x & ~(~0 << n));
	return (x);
	// return ((x >> (p + 1 - n) & ~(~0 << n));
}


// int main(void)
// {
// 	int unsigned x = 0b10011101;
// 	x = get_bits(x, 3, 2);
// 	x = x;
// }

// /*
// x = 0b 1001 1101
// p = 3
// n = 2
// */