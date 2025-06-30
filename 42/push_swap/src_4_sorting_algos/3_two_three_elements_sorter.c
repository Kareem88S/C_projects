/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_two_three_elements_sorter.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 02:32:39 by kasherif          #+#    #+#             */
/*   Updated: 2025/03/31 02:32:39 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

int			two_element_sort(t_ctr *tcon, t_stack_status *stats);
int			three_element_sort(t_ctr *tcon, t_stack_status *stats, int *ranks);
static void	sorting_in_empty_stack(t_ctr *tcon, int *nums, t_stack s);
static void	sorting_as_sub_stack(t_ctr *tcon, int *nums, t_stack s);

int	two_element_sort(t_ctr *tcon, t_stack_status *stats)
{
	if ((stats->stack == STACK_A && stats->norm_arr[0] > stats->norm_arr[1])
		|| (stats->stack == STACK_B && stats->norm_rev[0] > stats->norm_rev[1]))
		moving(tcon, stats->stack, SS);
	return (SORTED);
}

/*
Checks if already in sorted order.
Otherwise checks if can be sorted with a swap.
Else calls helper to sort remaining possibilities:
	either as sole elements (cheap)
	or as sub-stack within stack of more elements (limits rotation options)
else, call helper
*/


// LOOK for remainables!!!!
int	three_element_sort(t_ctr *tcon, t_stack_status *stats, int *ranks)
{
	int	top;
	int	mid;
	int	bot;

	top = ranks[0];
	mid = ranks[1];
	bot = ranks[2];
	if ((bot > mid) && (bot > top) && (mid > top))
		return (SORTED);
	if ((bot > mid) && (bot > top) && (mid < top))
	{
		moving(tcon, stats->stack, SS);
		return (SORTED);
	}
	if (stats->or_is_sub_stack == 0)
	{
		sorting_in_empty_stack(tcon, ranks, stats->stack);
		return (SORTED);
	}
	sorting_as_sub_stack(tcon, ranks, stats->stack);
	return (SORTED);
}

static void	sorting_as_sub_stack(t_ctr *tcon, int *ranks, t_stack s)
{
	const int		top = ranks[0];
	const int		mid = ranks[1];
	const int		bot = ranks[2];

	if ((bot > mid) && (bot < top) && (mid < top))
		moving(tcon, s, SS);
	if (((bot < mid) && (bot > top) && (mid > top))
		|| ((bot > mid) && (bot < top) && (mid < top)))
	{
		moving(tcon, s, RR);
		moving(tcon, s, SS);
		moving(tcon, s, RRR);
	}
	if ((bot < mid) && (mid < top) && (bot < top))
		moving(tcon, s, SS);
	if (((bot < mid) && (bot < top) && (mid > top))
		|| ((bot < mid) && (mid < top) && (bot < top)))
	{
		moving(tcon, s, RR);
		moving(tcon, s, SS);
		moving(tcon, s, RRR);
		moving(tcon, s, SS);
	}
}

static void	sorting_in_empty_stack(t_ctr *tcon, int *ranks, t_stack s)
{
	const int	top = ranks[0];
	const int	mid = ranks[1];
	const int	bot = ranks[2];

	if ((bot < mid) && (bot > top) && (mid > top))
	{
		moving(tcon, s, RRR);
		moving(tcon, s, SS);
	}
	else if ((bot > mid) && (bot < top) && (mid < top))
		moving(tcon, s, RR);
	else if ((bot < mid) && (bot < top) && (mid > top))
		moving(tcon, s, RRR);
	else if ((bot < mid) && (bot < top) && (mid < top))
	{
		moving(tcon, s, RR);
		moving(tcon, s, SS);
	}
}
