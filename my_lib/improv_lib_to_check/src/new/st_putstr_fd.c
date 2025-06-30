/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:46:26 by kasherif          #+#    #+#             */
/*   Updated: 2025/02/09 22:46:26 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_additions.h"

size_t	st_putstr_fd(char *s, int fd)
{
	size_t	len;
	char	*counter_ptr;

	if (fd < 0)
		return (0);
	if (!s)
		s = "(null)";
	counter_ptr = s;
	len = 0;
	while (*counter_ptr++)
		len++;
	write(fd, s, len);
	return (len);
}
