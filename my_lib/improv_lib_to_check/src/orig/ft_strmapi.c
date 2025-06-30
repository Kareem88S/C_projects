/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:03:23 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/27 16:03:23 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "../libft.h"

/*
Map / Transform
Applies the function 'f' to each character in string 's', passing its index 
	as the first argument and the character itself as the second. 
A new string is created (malloc) to collect the results 
	from the successive applications of f.
Returns a new string resulting of the successive applications of 'f'; 
	NULL if the memory allocations failed.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_string;
	unsigned int	index;

	if (!s || !f)
		return (NULL);
	new_string = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		new_string[index] = f(index, s[index]);
		index++;
	}
	new_string[index] = '\0';
	return (new_string);
}
