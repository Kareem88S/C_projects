/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:31:03 by kasherif          #+#    #+#             */
/*   Updated: 2025/03/08 18:31:03 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

t_mv		swap_move(t_ctr *tcon, t_mv cmd);
static void	swap_top_nodes(t_ctr *tcon, t_n *old_top, t_mv cmd);
static void	relink_tcon(t_n **ctrl_top, t_n **ctrl_bot, t_n **top, t_n **bot);

/*
Check if circular list has more than 1 element.
If 0 or 1 element(s), function returns w/o performing actions.
sa (swap a): 	Swap the first 2 elements at the top of stack a.
					Do nothing if there is only one or no elements.
sb (swap b): 	Swap the first 2 elements at the top of stack b.
					Do nothing if there is only one or no elements.
ss : 			sa and sb at the same time.
Returns te performed action.
*/
t_mv	swap_move(t_ctr *tcon, t_mv cmd)
{
	if (cmd == SA && (!tcon->a_top || tcon->a_top->previous == tcon->a_top))
		return (NO_ACTION_PERFORMED);
	if (cmd == SB && (!tcon->b_top || tcon->b_top->previous == tcon->b_top))
		return (NO_ACTION_PERFORMED);
	if (cmd == SS)
		if ((!tcon->b_top || tcon->b_top->previous == tcon->b_top)
			&& (!tcon->a_top || tcon->a_top->previous == tcon->a_top))
			return (NO_ACTION_PERFORMED);
	if ((cmd == SA || cmd == SS) && tcon->a_top
		&& tcon->a_top->previous != tcon->a_top)
	{
		swap_top_nodes(tcon, tcon->a_top, SA);
		if (cmd == SS && (!tcon->b_top || tcon->b_top->next == tcon->b_top))
			cmd = SA;
	}
	if ((cmd == SB || cmd == SS) && tcon->b_top
		&& tcon->b_top->previous != tcon->b_top)
	{
		swap_top_nodes(tcon, tcon->b_top, SB);
		if (cmd == SS && (!tcon->a_top || tcon->a_top->next == tcon->a_top))
			cmd = SB;
	}
	print_operation(cmd);
	return (cmd);
}

static void	swap_top_nodes(t_ctr *tcon, t_n *old_top, t_mv cmd)
{
	int	only_two_elements;
	t_n	*second_aka_nw_top;
	t_n	*third;
	t_n	*bottom;

	bottom = old_top->next;
	second_aka_nw_top = old_top->previous;
	only_two_elements = 0;
	if ((bottom == second_aka_nw_top) && (bottom->next == old_top))
		only_two_elements = 1;
	if (!only_two_elements)
	{
		third = second_aka_nw_top->previous;
		third->next = old_top;
		old_top->previous = third;
		old_top->next = second_aka_nw_top;
		second_aka_nw_top->previous = old_top;
		second_aka_nw_top->next = bottom;
		bottom->previous = second_aka_nw_top;
	}
	if (cmd == SA)
		relink_tcon(&tcon->a_top, &tcon->a_bottom, &second_aka_nw_top, &bottom);
	if (cmd == SB)
		relink_tcon(&tcon->b_top, &tcon->b_bottom, &second_aka_nw_top, &bottom);
}

static void	relink_tcon(t_n **ctrl_top, t_n **ctrl_bot, t_n **top, t_n **bot)
{
	*ctrl_top = *top;
	*ctrl_bot = *bot;
}
