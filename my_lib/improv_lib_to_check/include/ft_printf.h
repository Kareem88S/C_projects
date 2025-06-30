/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:55:10 by kasherif          #+#    #+#             */
/*   Updated: 2025/02/11 01:52:29 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PF_STD_OUT 1
# define PF_INVALID -1
# define HXLOW "0123456789abcdef"
# define HXUP "0123456789ABCDEF"
# define PF_BASE_DIGIT "0123456789"

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <errno.h>
# include "../lift.h"

int		ft_printf(const char *str, ...);
size_t	handle_specifiers(va_list args, char specifier, int fd);
size_t	handle_ptr(va_list args, int fd);

#endif
