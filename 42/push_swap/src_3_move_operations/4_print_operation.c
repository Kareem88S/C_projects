/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_print_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:20:33 by kasherif          #+#    #+#             */
/*   Updated: 2025/03/18 22:20:33 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

void	print_operation(t_mv cmd)
{
	g_moves++;
	if (cmd == PA)
		write(1, "PA\n", 3);
	else if (cmd == PB)
		write(1, "PB\n", 3);
	else if (cmd == SA)
		write(1, "SA\n", 3);
	else if (cmd == SB)
		write(1, "SB\n", 3);
	else if (cmd == SS)
		write(1, "SS\n", 3);
	else if (cmd == RA)
		write(1, "RA\n", 3);
	else if (cmd == RB)
		write(1, "RB\n", 3);
	else if (cmd == RR)
		write(1, "RR\n", 3);
	else if (cmd == RRA)
		write(1, "RRA\n", 4);
	else if (cmd == RRB)
		write(1, "RRB\n", 4);
	else if (cmd == RRR)
		write(1, "RRR\n", 4);
}
