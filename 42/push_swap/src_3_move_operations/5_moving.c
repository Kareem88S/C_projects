/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_moving.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:46:14 by kasherif          #+#    #+#             */
/*   Updated: 2025/06/20 21:37:26 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

#define ADD_ONE_MOVE 1

int			moving(t_ctr *tcon, t_stack stack, t_mv move);
static void	invoke_rotate(t_ctr *tcon, t_stack stack);
static void	invoke_rotate_rev(t_ctr *tcon, t_stack stack);
static void	invoke_swap(t_ctr *tcon, t_stack stack);

/*
Called as follows:
	moving(tcon, STACK_A, SS); == Swaps in stack A, unless SS possible
	moving(tcon, STACK_A, RR); == Rotates in stack A, unless RR possible
	moving(tcon, STACK_A, RRR); == Reverse rotates in stack A, unless RRR possible
	moving(tcon, STACK_A, ANY_PUSH); == Pushed 'FROM A' to stack b.
*/
int	moving(t_ctr *tcon, t_stack stack, t_mv move)
{
	if (move == ANY_PUSH)
	{
		if (stack == STACK_A)
			push_move(tcon, PB);
		else if (stack == STACK_B)
			push_move(tcon, PA);
	}
	if (move == RR)
		invoke_rotate(tcon, stack);
	if (move == RRR)
		invoke_rotate_rev(tcon, stack);
	if (move == SS)
		invoke_swap(tcon, stack);
	return (ADD_ONE_MOVE);
}

static void	invoke_rotate(t_ctr *tcon, t_stack stack)
{
	const t_n	*at = tcon->a_top;
	const t_n	*bt = tcon->b_top;

	if ((at && bt) && ((stack == BOTH_STACKS)
		|| (stack == STACK_A && bt->rotate == WAITING_FOR_RR)
		|| (stack == STACK_B && at->rotate == WAITING_FOR_RR)))
	{
		tcon->a_top->rotate = NONE;
		tcon->b_top->rotate = NONE;
		rotate_move(tcon, RR);
	}
	else if (stack == STACK_A && tcon->a_top)
	{
		tcon->a_top->rotate = NONE;
		rotate_move(tcon, RA);
	}
	else if (stack == STACK_B && tcon->b_top)
	{
		tcon->b_top->rotate = NONE;
		rotate_move(tcon, RB);
	}
}

/*
Accepts a RRR double reverse rotate, if the desired stack is passed,
and the other stack's "waiting switch" is activated.  
*/
static void	invoke_rotate_rev(t_ctr *tcon, t_stack stack)
{
	const t_n	*at = tcon->a_top;
	const t_n	*bt = tcon->b_top;

	if ((at && bt) && ((stack == BOTH_STACKS)
		|| (stack == STACK_A && bt->rotate_rev == WAITING_FOR_RRR)
		|| (stack == STACK_B && at->rotate_rev == WAITING_FOR_RRR)))
	{
		tcon->a_top->rotate_rev = NONE;
		tcon->b_top->rotate_rev = NONE;
		rotate_move(tcon, RRR);
	}

	else if (stack == STACK_A && tcon->a_top)
	{
		tcon->a_top->rotate_rev = NONE;
		rotate_move(tcon, RRA);
	}
	else if (stack == STACK_B && tcon->b_top)
	{
		tcon->b_top->rotate_rev = NONE;
		rotate_move(tcon, RRB);
	}
}

/*
Accepts a SS double swap, if the desired stack is passed, 
and the other stack's "waiting switch" is activated.  
*/
static void	invoke_swap(t_ctr *tcon, t_stack stack)
{
	const t_n	*at = tcon->a_top;
	const t_n	*bt = tcon->b_top;

	if ((at && bt) && ((stack == BOTH_STACKS)
		|| (at->swap == WAITING_FOR_SS && stack == STACK_B)
		|| (bt->swap == WAITING_FOR_SS && stack == STACK_A)))
	{
		tcon->a_top->swap = NONE;
		tcon->b_top->swap = NONE;
		swap_move(tcon, SS);
	}
	else if (at && stack == STACK_A)
	{
		tcon->a_top->swap = NONE;
		swap_move(tcon, SA);
	}
	else if (bt && stack == STACK_B)
	{
		tcon->b_top->swap = NONE;
		swap_move(tcon, SB);
	}
}
