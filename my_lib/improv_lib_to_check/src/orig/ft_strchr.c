/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:20:38 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/17 18:20:38 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Locate character in string.
// Returns a pointer to the FIRST occurrence of the character c in the string s.
char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;

	chr = (unsigned char) c;
	while (*s)
	{
		if (*s == chr)
			return ((char *) s);
		s++;
	}
	if (chr == '\0')
		return ((char *) s);
	return (NULL);
}
