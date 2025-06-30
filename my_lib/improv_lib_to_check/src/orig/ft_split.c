/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:04:08 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/27 16:04:08 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "../libft.h"

static size_t	count_words(char const *s, const char c);
static size_t	static_wordlen(char const *s, const char c);
static char		**free_allocated_on_error(size_t i, char **p_result);
static int		actual_split(char const *s, char c, size_t words, char **split);

/*
Split a string into an array of words.
Allocate (malloc) and returns an array of strings obtained by splitting s 
	with the character c, used as delimiter. 
Skip spaces, consequtive delimiters
End strings with \0. End array with NULL.
*/
char	**ft_split(char const *s, char c)
{
	char	**p_result;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	if (words == 0)
		return ((char **)ft_calloc(1, sizeof(char *)));
	p_result = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!p_result)
		return (NULL);
	if (actual_split(s, c, words, p_result) == 0)
		return (NULL);
	return (p_result);
}

static int	actual_split(char const *s, char c, size_t words, char **split)
{
	size_t	i;
	size_t	pos_in_s;
	size_t	wordlen;

	i = 0;
	pos_in_s = 0;
	while (i < words)
	{
		while (s[pos_in_s] != '\0' && s[pos_in_s] == c)
			pos_in_s++;
		wordlen = static_wordlen(&s[pos_in_s], c);
		split[i] = ft_calloc(wordlen + 1, sizeof(char));
		if (split[i] == NULL)
		{
			free_allocated_on_error(i, split);
			return (0);
		}
		ft_strlcpy(split[i], &s[pos_in_s], wordlen + 1);
		pos_in_s += wordlen;
		i++;
	}
	split[i] = NULL;
	return (1);
}

static char	**free_allocated_on_error(size_t i, char **p_result)
{
	while (i-- > 0)
	{
		if (p_result[i] != NULL)
			free(p_result[i]);
	}
	free(p_result);
	return (NULL);
}

static size_t	count_words(char const *s, const char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (words);
}

static size_t	static_wordlen(char const *s, const char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}
