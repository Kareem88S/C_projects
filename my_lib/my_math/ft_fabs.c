/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:43:56 by kasherif          #+#    #+#             */
/*   Updated: 2025/05/12 11:49:49 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	fabs(double x);

union	u_double;
{
	double				d;
	unsigned long long	u;
}	;

double	fabs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}
