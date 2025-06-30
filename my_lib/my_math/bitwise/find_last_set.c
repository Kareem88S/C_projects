/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:47:19 by kasherif          #+#    #+#             */
/*   Updated: 2025/05/14 16:26:31 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// char	find_last_set(int x);


/*
fls
returns the position (1-based) of the most significant bit (MSB) that is set.
*/
unsigned	find_last_set(int x)
{
	const char	bits = sizeof(x) * 8;
	char		position;

	if (x == 0)
		return (0);
	position = 0;
// 	while (x)
// 	{
		
// 	}	
	return (0);
}

int main()
{
	find_last_set(1);
}

/*
get n bits, starting from position p, found in x.
*/
//				1000 1101		4		2
unsigned getbits(unsigned x, int p, int n)
{
	unsigned int	new_nbr;
	int				shift;
	unsigned char	mask;

		//	4 + 1	- 2
	shift = (p + 1 - n);
	mask = ~(~0 << n);

// x == 0b 1000 1101	== 0x8d		128+13=141 
//		>> 3
// x == 0b 0001 0001	== 0x11		16+1=17
	new_nbr = x >> 3;

	new_nbr = x & new_nbr;
//	 == 0b 0000 0001

    return (x >> (p + 1 - n)) & ~(~0 << n);
}