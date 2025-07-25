/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:07:06 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/23 15:07:06 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// static size_t	ft_strlen(const char *str);

/*
Allocate (with malloc(3)) and return a new string from the string s.
    This new string starts at index 'start' and has a maximum size of 'len'.
returns the new string; NULL if the memory allocation failed.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	actual_len;

	if (!s)
		return (NULL);
	actual_len = ft_strlen(s);
	if (start >= actual_len)
		return (ft_calloc(1, 1));
	if (len > (actual_len - start))
		len = actual_len - start;
	new = ft_calloc(len + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s + start, len + 1);
	return (new);
}

// size_t	ft_strlen(const char *str)
// {
// 	size_t	counter;

// 	counter = 0;
// 	while (str[counter] != '\0')
// 		counter++;
// 	return (counter);
// }

// int main(void)
// {
// 	printf("%s\n", ft_substr("Bonjour comment ca va?", 5, 8));
// 	// => "ur comme"
// }