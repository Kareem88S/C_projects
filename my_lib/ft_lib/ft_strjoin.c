/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:09:29 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/23 15:09:29 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Concatenates 2 strings in a new string.
Allocates (malloc) and returns a new string 
	resulting from the concatenation of s1 and s2.
Returns the new string; NULL if the memory allocation failed.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*joined_str;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined_str = ft_calloc(size, sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	ft_strlcat(joined_str, s1, size);
	ft_strlcat(joined_str, s2, size);
	return (joined_str);
}
