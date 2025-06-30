/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:06:48 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/23 15:06:48 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	needle_reader(const char *needle, const char *haystack, size_t len);

/*
Locates the first occurence of the null-terminated string needle 
	in the string haystack
	where not more than len characters are searched.
Returns:
	Pointer to the first character of the first occurence of needle		
	If needle is an empty string, haystack is returned					---
	If needle occurs nowhere in haystack, NULL is returned 				---
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*hay;

	if (!*needle)
		return ((char *) haystack);
	hay = haystack;
	while (*hay && len)
	{
		if (*needle == *hay)
			if (needle_reader(needle, hay, len))
				return ((char *) hay);
		hay++;
		len--;
	}
	return (NULL);
}

static int	needle_reader(const char *needle, const char *haystack, size_t len)
{
	while (*haystack && *needle && *haystack == *needle && len)
	{
		haystack++;
		needle++;
		len--;
	}
	if (*needle == '\0')
		return (1);
	return (0);
}

// int main(void)
// {
//     const char *haystack = "Hello, world!";
//     const char *needle = "world";

//     // Test case where `needle` is found.
//     char *result = ft_strnstr(haystack, needle, 12);
//     if (result)
//         printf("Found: %s\n", result);  // Expected: "Found: world!"
//     else
//         printf("Not found\n");

//     // Test case where `needle` is not found.
//     result = ft_strnstr(haystack, needle, 5);
//     if (result)
//         printf("Found: %s\n", result);
//     else
//         printf("Not found\n");  // Expected: "Not found"

//     return 0;
// }
