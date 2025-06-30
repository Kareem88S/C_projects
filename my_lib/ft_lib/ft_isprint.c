/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:08:01 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/23 17:50:02 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Printing character test (space character inclusive)
int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
