/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:16:23 by kasherif          #+#    #+#             */
/*   Updated: 2025/02/11 02:08:12 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "../libft.h"

static const char	*trim_suffix(char const *start_s1, char const *end_s1,	
						char const *set);
static const char	*trim_prefix(char const *s1, char const *set);

/*
Trims character set from string - beginning AND end.
The set can theoretically contain any number of characters, with no maximum c's.
Allocates (malloc) and returns a copy of s1, without the characters 
	specified in set at the beginning and the end of s1.
Returns a trimmed copy of s1; NULL if the memory allocation failed.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*trimmed_start;
	const char	*trimmed_end;
	char		*trimmed_str;
	size_t		len;

	if (!s1)
		return (NULL);
	trimmed_start = s1;
	if (!set || *set == '\0')
		return (ft_strdup(s1));
	trimmed_end = trim_suffix(s1, s1 + (ft_strlen(s1) - 1), set);
	if (trimmed_end < trimmed_start)
		return (ft_strdup(""));
	trimmed_start = trim_prefix(s1, set);
	len = trimmed_end - trimmed_start + 1;
	trimmed_str = (char *) malloc((len + 1) * sizeof(char));
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, trimmed_start, len + 1);
	return (trimmed_str);
}

static const char	*trim_prefix(char const *s1, char const *set)
{
	const char	*set_iterator;

	while (*s1)
	{
		set_iterator = set;
		while (*set_iterator)
		{
			if (*s1 == *set_iterator)
				break ;
			set_iterator++;
		}
		if (*set_iterator == '\0')
			break ;
		s1++;
	}
	return (s1);
}

static const char	*trim_suffix(char const *start_s1, char const *end_s1,	
						char const *set)
{
	const char	*set_iterator;

	while (end_s1 >= start_s1)
	{
		set_iterator = set;
		while (*set_iterator)
		{
			if (*end_s1 == *set_iterator)
				break ;
			set_iterator++;
		}
		if (*set_iterator == '\0')
			break ;
		end_s1--;
	}
	return (end_s1);
}
