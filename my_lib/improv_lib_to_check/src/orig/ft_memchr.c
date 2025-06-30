/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:38:06 by kasherif          #+#    #+#             */
/*   Updated: 2025/02/11 02:02:35 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Locates the first occurence of c (convered to an unsigned char) in string s.
Returns a pointer to the byte located, 
	or NULL if no such byte exists within n bytes.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = s;
	while (n--)
	{
		if (*p == (unsigned char) c)
			return ((void *) p);
		p++;
	}
	return (NULL);
}

// #include <stdio.h>

// int main(void)
// {

// 	char *string = "string";
// 	printf("before: %p\n", &string[1]);

// 	printf("after: %p\n", ft_memchr(string, 't', 5));

// 	return (0);
// }