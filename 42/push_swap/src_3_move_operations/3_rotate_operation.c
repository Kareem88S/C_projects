/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations copy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:31:22 by kasherif          #+#    #+#             */
/*   Updated: 2025/03/08 18:31:22 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

t_mv		rotate_move(t_ctr *tcon, t_mv cmd);
static t_mv	forward_print_and_move(t_ctr *tcon, t_mv cmd, t_n *a, t_n *b);
static t_mv	reverse_print_and_move(t_ctr *tcon, t_mv cmd, t_n *a, t_n *b);
static void	rotate_forward(t_n **top, t_n **bottom);
static void	rotate_reverse(t_n **top, t_n **bottom);

/*
		ra (rotate a): 
Shift up all elements of stack a by 1. The first element becomes the last one.
		rb (rotate b): 
Shift up all elements of stack b by 1. The first element becomes the last one.
		rr : 
ra and rb at the same time.
		rra (reverse rotate a): 
Shift down all elements of stack a by 1. The last element becomes the first one.
		rrb (reverse rotate b): 
Shift down all elements of stack b by 1. The last element becomes the first one.
		rrr : 
rra and rrb at the same time.
*/

/*
Handles the stack-rotation moves.
Forward rotations;
Reverse rotations.
	ra/rb/rr (both ra & rb): 
		- Shift up all elements.
	rra/rrb/rrr (both rra & rrb): 
		- Shift down all elements. 
Function checks if there is any content in the a- and/or b-stack.
Then calls the '..print_and_move'-function, 
	which passes the corresponding pointers (potentially NULL) to the stacks, 
	and, if all goes well, prints, performs and returns the action/command.
*/
t_mv	rotate_move(t_ctr *tcon, t_mv cmd)
{
	t_n	*a;
	t_n	*b;

	a = tcon->a_top;
	b = tcon->b_top;
	if (cmd == RA || cmd == RRA)
		if ((a == NULL) || (a->next == a))
			return (NO_ACTION_PERFORMED);
	if (cmd == RB || cmd == RRB)
		if ((b == NULL) || (b->next == b))
			return (NO_ACTION_PERFORMED);
	if (cmd == RR || cmd == RRR)
		if ((b == NULL || b->next == b) && (a == NULL || a->next == a))
			return (NO_ACTION_PERFORMED);
	if (cmd == RA || cmd == RB || cmd == RR)
		cmd = forward_print_and_move(tcon, cmd, a, b);
	if (cmd == RRA || cmd == RRB || cmd == RRR)
		cmd = reverse_print_and_move(tcon, cmd, a, b);
	return (cmd);
}

static t_mv	forward_print_and_move(t_ctr *tcon, t_mv cmd, t_n *a, t_n *b)
{
	if ((cmd == RA || cmd == RR) && (a && a->next != a))
	{
		if (cmd == RA || (cmd == RR && (!b || b->next == b)))
		{
			cmd = RA;
			print_operation(RA);
		}
		rotate_forward(&(tcon->a_top), &(tcon->a_bottom));
	}
	if ((cmd == RB || cmd == RR) && (b && b->next != b))
	{
		if (cmd == RB || (cmd == RR && (!a || a->next == a)))
		{
			cmd = RB;
			print_operation(RB);
		}
		rotate_forward(&(tcon->b_top), &(tcon->b_bottom));
	}
	if (cmd == RR)
		print_operation(cmd);
	return (cmd);
}

static t_mv	reverse_print_and_move(t_ctr *tcon, t_mv cmd, t_n *a, t_n *b)
{
	if ((cmd == RRA || cmd == RRR) && (a && a->next != a))
	{
		if (cmd == RRA || (cmd == RRR && (!b || b->next == b)))
		{
			cmd = RRA;
			print_operation(RRA);
		}
		rotate_reverse(&(tcon->a_top), &(tcon->a_bottom));
	}
	if ((cmd == RRB || cmd == RRR) && (b && b->next != b))
	{
		if (cmd == RRB || (cmd == RRR && (!a || a->next == a)))
		{
			cmd = RRB;
			print_operation(RRB);
		}
		rotate_reverse(&(tcon->b_top), &(tcon->b_bottom));
	}
	if (cmd == RRR)
		print_operation(cmd);
	return (cmd);
}

static void	rotate_forward(t_n **top, t_n **bottom)
{
	*bottom = *top;
	*top = (*top)->previous;
}

static void	rotate_reverse(t_n **top, t_n **bottom)
{
	*top = *bottom;
	*bottom = (*bottom)->next;
}
