/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:55:10 by kasherif          #+#    #+#             */
/*   Updated: 2025/02/04 17:42:22 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef FT_PRINTF_H
// # define FT_PRINTF_H

// # define PF_STD_OUT 1
// # define PF_INVALID -1
// # define HEX_LOWER "0123456789abcdef" // Hexa lower case base
// # define HEX_UPPER "0123456789ABCDEF" // Hexa uppercase base
// # define DIGB "0123456789" // digit base

// # include <unistd.h>
// # include <stdarg.h>
// # include <stdlib.h>
// # include <errno.h>

// int		ft_printf(const char *str, ...);
// size_t	handle_specifiers(va_list args, char *specifier, int fd);
// size_t	handle_ptr(va_list args, int fd);
// size_t	ft_putstr_fd(char *s, int fd);
// char	*ft_strchr(const char *s, int c);
// size_t	ft_putchar_fd(const char c, int fd);
// size_t	ft_putnbr_base_fd(long n, const char *base, int fd);
// size_t	ft_putnbr_base_uns_fd(unsigned long n, const char *base, int fd);

// #endif

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

int		ft_printf(const char *str, ...);
size_t	handle_specifiers(va_list args, char specifier, int fd);
size_t	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putnbr_base_fd(long n, const char *base, int fd);
size_t	ft_putnbr_base_uns_fd(unsigned long n, const char *base, int fd);
size_t	handle_ptr(va_list args, int fd);

#endif