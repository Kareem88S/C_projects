/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_null.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:14:36 by kasherif          #+#    #+#             */
/*   Updated: 2025/06/16 09:17:06 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function requires a pointer to the freeable object.
The dereferenced object will be freed, and the address set to NULL.
Expects a void pointer, so the caller must always cast to void**
*/
void	free_and_null(void **ptr)
{
	if (ptr && *ptr)
	{
		free (*ptr);
		*ptr = NULL;
	}
}
