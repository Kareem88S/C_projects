/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:05:25 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/23 15:05:25 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// compares the first n bytes (each interpreted as unsigned char) 
// 	of the memory areas s1 and s2.
// returns an integer if the first n bytes of s1 is 
// 	less than, to match, or be greater than the first n bytes of s2
// Extra info: 
//	Subtraction between two unsigned char values will already return an int:
// 	The subtraction of two unsigned char values will promote them 
//	to int !!!automatically!!!, 
// 	as per C's integer promotion rules. So no cast needed (still kept them)
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*one;
	const unsigned char	*two;

	one = s1;
	two = s2;
	while (n--)
	{
		if (*one != *two)
			return ((int) *one - (int) *two);
		one++;
		two++;
	}
	return (0);
}
