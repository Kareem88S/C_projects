/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:49:28 by kasherif          #+#    #+#             */
/*   Updated: 2025/02/09 22:49:28 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_additions.h"

size_t	st_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return (0);
	write (fd, &c, 1);
	return (1);
}
