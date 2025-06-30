/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:18:18 by kasherif          #+#    #+#             */
/*   Updated: 2024/10/16 15:18:18 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	move_forwards(unsigned char *d, const unsigned char *s, size_t n);
static void	move_backwards(unsigned char *d, const unsigned char *s, size_t n);

/*
Copy byte string.
Copies len bytes from string src to string dest.
The two strings may overlap; the copy is always done in a non-destructive manner.
Returns the original value of dest.
No safeguards: dest or src NULL? Seg fault
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_ptr;
	unsigned char	*s_ptr;

	d_ptr = (unsigned char *)dest;
	s_ptr = (unsigned char *)src;
	if (d_ptr < s_ptr)
		move_forwards(d_ptr, s_ptr, n);
	else if (d_ptr > s_ptr)
	{
		move_backwards(d_ptr, s_ptr, n);
	}
	return (dest);
}

static void	move_forwards(unsigned char *d, const unsigned char *s, size_t n)
{
	while (n--)
		*d++ = *s++;
}

static void	move_backwards(unsigned char *d, const unsigned char *s, size_t n)
{
	d = d + n;
	s = s + n;
	while (n--)
		*--d = *--s;
}

// addr	0x11	0x12	0x13	0x14	0x15	0x16	
// src	h		a		l		l		o		.		
// dest							h		a		l		
// --------------------------------------------------
// addr	0x11	0x12	0x13	0x14	0x15	0x16	
// src							h		a		l		
// dest	h		a		l		l		o		.		