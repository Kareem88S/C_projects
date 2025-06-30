/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_additions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 02:10:33 by kasherif          #+#    #+#             */
/*   Updated: 2025/02/11 02:10:33 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_ADDITIONS_H
# define LIB_ADDITIONS_H

# include <unistd.h>

size_t	ft_strcspn(const char *s, const char *reject);
size_t	st_putstr_fd(char *s, int fd);
size_t	st_putchar_fd(char c, int fd);
size_t	st_putnbr_base_fd(long n, const char *base, int fd);
size_t	st_putnbr_base_unsigned_fd(unsigned long n, const char *base, int fd);
int		ft_atoll(const char *nptr);

#endif