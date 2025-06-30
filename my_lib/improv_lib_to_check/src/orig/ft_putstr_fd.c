/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:06:45 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/27 16:06:45 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "../libft.h"

/*
Outputs the string ’s’ to the given file descriptor.
s: The string to output.
fd: The file descriptor on which to write.
---
File descriptors: 
	an integer that uniquely identifies an open file within a process.
Index to a table in the kernel: information about all open files for a process
Each process has a file descriptor table 
	where the OS keeps track of the open files.
Three standard file descriptors are always open:
	0 - Standard Input (stdin): Usually connected to the keyboard;
	1 - Standard Output (stdout): Usually connected to the terminal or console;
	2 - Standard Error (stderr): Also typically connected to the terminal, 
		often used to output error messages.
	3+	Available for files, sockets, pipes, or other resources.
			with functions like open(), socket(), or pipe()
The maximum number of file descriptors: a soft limit (+/- 1024)and a hard limit
ulimit -n  # View soft limit for open files -- -Hn hard limit
*/
void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	write(fd, s, ft_strlen(s));
	return ;
}
