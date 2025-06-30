/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:21:43 by kasherif          #+#    #+#             */
/*   Updated: 2025/02/11 02:08:01 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Locate character in string. -- Reverse
// Returns a pointer to the LAST occurrence of the character c in the string s.
char	*ft_strrchr(const char *s, int c)
{
	const char	*end_of_s;

	end_of_s = s;
	while (*end_of_s)
		end_of_s++;
	if (c == '\0')
		return ((char *) end_of_s);
	while (end_of_s >= s)
	{
		if (*end_of_s == (unsigned char) c)
		{
			return ((char *) end_of_s);
		}
		end_of_s--;
	}
	return (NULL);
}

// int main(void)
// {
// 	const char *str = "hoi";
// 	printf("%p\n", &str[3]);
// 	printf("%p\n", ft_strrchr(str, '\0'));
// }
