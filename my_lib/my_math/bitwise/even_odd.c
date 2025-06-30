/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_odd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:07:46 by kasherif          #+#    #+#             */
/*   Updated: 2025/05/14 10:08:59 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
returns 0 if nbr == zero
returns 1 if nbr == odd
returns 2 if nbr == even
*/
char	even_odd_checker(int nbr)
{
	if (nbr == 0)
		return (0);
	if (nbr & 0b1)
		return (1);
	return (2);
}