/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:06:14 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/23 15:06:14 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "../libft.h"

/*
Save a copy of a string.
Allocates sufficient memory for a copy of the string s1, does the copy, 
	and returns a pointer to it.
*/
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	char	*temp_dup;

	len = ft_strlen(s);
	dup = (char *) malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	temp_dup = dup;
	while (*s)
	{
		*dup = *s;
		s++;
		dup++;
	}
	*dup = '\0';
	return ((char *) temp_dup);
}
