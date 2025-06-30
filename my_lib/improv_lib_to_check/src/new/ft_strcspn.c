/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:59:01 by kasherif          #+#    #+#             */
/*   Updated: 2025/02/11 01:59:01 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strcspn() function calculates the length of the initial segment of s 
	which consists entirely of bytes not in reject.
Returns # of bytes (accepted)
*/
size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t 		count_accepted;
	const char	*r_ptr;

	count_accepted = 0;
	while (s[count_accepted])
	{
		r_ptr = reject;
		while (*r_ptr)
			if (*(r_ptr++) == s[count_accepted])
				return (count_accepted);
		count_accepted++;
	}
	return (count_accepted);
}