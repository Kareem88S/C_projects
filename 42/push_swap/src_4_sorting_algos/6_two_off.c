/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_two_off.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:04:36 by kasherif          #+#    #+#             */
/*   Updated: 2025/07/07 19:34:00 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

#define FIVE 5
#define THREE 3

int			max_two_off(t_ctr *tcon, t_stack_status *stats);
static int	handle_stack_b(t_ctr *tcon, t_stack_status *stats);
static int	handle_few_out_of_scopes(t_ctr *tcon, t_stack_status *stats);
static int	handle_no_out_of_scopes(t_ctr *tcon, t_stack_status *stats);
static int	rotate_and_reverse_rotate(t_ctr *tcon, t_stack_status *stats);

/*
stats->or_is_sub_stack indicates if the stack of origin contains other elements
	next to the sub-stack that is being handled. If it is 0, then there are no
	other elements. If there are, this var indicates how many.
oos_count == out-of-scope count
Function forward-rotates elements until all, except the last three, are away from
	the top, and sorts in the process.
Then checks the cheapest way to return elements to the top.
- 1) no 'out-of-scope'-elements == finalize by rotating the last three
- 2) few 'out-of-scope'-elements == finalize by rotating last three and the oos
- 3) no cheap way to forward-rotate == reverse elements back how they went.
*/
int	max_two_off(t_ctr *tcon, t_stack_status *stats)
{
	// try 5-sorter to RR instead of push if extreme

	if (stats->stack == STACK_B)
		return (handle_stack_b(tcon, stats));
	if (stats->or_is_sub_stack == 0)
		return (handle_no_out_of_scopes(tcon, stats));
	if (stats->or_is_sub_stack < stats->stack_size - FIVE)
		return (handle_few_out_of_scopes(tcon, stats));
	else
		return (rotate_and_reverse_rotate(tcon, stats));
	return (INVALID);
}

/*
Most expensive:
Function is called if the sortable elements are fewer than 'out-of-scope's.
Forward-rotates all sortable elements minus the last five, then reverses the
	elements back to the top.
Sorts groups of five along the way.
*/
static int	rotate_and_reverse_rotate(t_ctr *tcon, t_stack_status *stats)
{
	int	i;

	sorting_manager(tcon, stats->or, FIVE, NULL);
	i = -1;
	while (++i < (stats->stack_size - FIVE))
	{
		if ((i % 3) == 0)
			sorting_manager(tcon, stats->or, FIVE, NULL);
		stats->rotated += moving(tcon, stats->stack, RR);
	}	
	sorting_manager(tcon, stats->or, FIVE, NULL);
	while (stats->rotated && i-- > 0)
	{
		stats->rotated -= moving(tcon, stats->other_stack, RRR);
		if (i % 2 == 0)
			sorting_manager(tcon, stats->or, THREE, NULL);
	}
	return (SORTED);
}

/*
Cheapest:
Function is only called if the sortable elements live in the stack alone, with
	no other 'out-of-scope' elements to block the way.
Forward-rotates all elements until the circle is complete and the original top
	is back at the top. 
Sorts groups of five along the way.
*/
static int	handle_no_out_of_scopes(t_ctr *tcon, t_stack_status *stats)
{
	int	i;

	sorting_manager(tcon, stats->or, FIVE, NULL);
	i = -1;
	while (++i < (stats->stack_size))
	{
		if ((i % 3) == 0)
			sorting_manager(tcon, stats->or, FIVE, NULL);
		moving(tcon, stats->stack, RR);
	}
	sorting_manager(tcon, stats->or, FIVE, NULL);
	return (SORTED);
}

/*
Medium cheap:
Function is only called if the sortable elements are in greater number that the
'out-of-scope' elements, blocking the way. 
Forward-rotates all elements, until the 'out-of-scope' elements are at the top.
	Then continues until the 'out-of-scope' elements are all out of the way.
Sorts groups of five along the way.
*/
static int	handle_few_out_of_scopes(t_ctr *tcon, t_stack_status *stats)
{
	int	i;

	sorting_manager(tcon, stats->or, FIVE, NULL);
	i = -1;
	while (++i < (stats->stack_size))
	{
		if (((i % 3) == 0) && (i < (stats->stack_size - FIVE)))
			sorting_manager(tcon, stats->or, FIVE, NULL);
		moving(tcon, stats->stack, RR);
	}
	while (++i < (stats->stack_size + stats->or_is_sub_stack))
		moving(tcon, stats->stack, RR);
	sorting_manager(tcon, stats->or, FIVE, NULL);
	return (SORTED);
}	

/*
Always cheap:
Function is only called when the sortable elements are located in stack B.
The function continuously sorts the top 5 elements, then pushes the every 3 to
	stack A. as a double check, the elements are again sorted in A, where the
	sorting algorithm supposedly returns SORTED directly. Curtesy sort-check.
*/
static int	handle_stack_b(t_ctr *tcon, t_stack_status *stats)
{
	int	i;
	
	i = -1;
	while (++i < (stats->stack_size - FIVE))
	{
		if (((i % 3) == 0) && (i < (stats->stack_size - FIVE)))
			sorting_manager(tcon, stats->or, FIVE, NULL);
		stats->pushed += moving(tcon, stats->stack, ANY_PUSH);
		if (((i % 3) == 0) && (i > FIVE))
			sorting_manager(tcon, stats->aux, FIVE, NULL);
	}
	sorting_manager(tcon, stats->or, FIVE, NULL);
	return (SORTED);
}
