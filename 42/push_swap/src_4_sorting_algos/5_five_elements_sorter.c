/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_five_elements_sorter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:28:52 by kasherif          #+#    #+#             */
/*   Updated: 2025/04/20 20:55:00 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

int			five_element_sort(t_ctr *tcon, t_stack_status *stats, int *ranks);
static int	displace_elements(t_ctr *tcon, t_stack_status *stats, int r[5]);
static int	displacement_helper(t_ctr *tcon, t_stack_status *stats, int r[5]);
static int	topextremes_situation(t_ctr *tcon, t_stack_status *stats, int r[5]);
static void	one_pushed(t_ctr *tcon, t_stack_status *stats);

#define FIVE_ELEMENTS 5
#define FOUR_ELEMENTS 4
#define THREE_ELEMENTS 3
#define TWO_ELEMENTS 2

/*
Activates if 5 elements need to be sorted. 
This function terminates if the most-extreme element is one-from, or at the top.
*/
int	five_element_sort(t_ctr *tcon, t_stack_status *stats, int *ranks)
{
	if (ranks[0] <= 1 && ranks[1] <= 1)
		return (topextremes_situation(tcon, stats, ranks));
	stats->pushed = displace_elements(tcon, stats, ranks);
	if (stats->pushed == 1)
	{
		one_pushed(tcon, stats);
		return (SORTED);
	}
	else if (stats->pushed == 2)
	{
		sorting_manager(tcon, stats->or, THREE_ELEMENTS, &stats->remainables);
		sorting_manager(tcon, stats->aux, TWO_ELEMENTS, &stats->remainables);
	}
	if (stats->remainables_ptr != NULL)
		stats->remainables = 0;
	while (stats->pushed > stats->remainables)
		stats->pushed -= moving(tcon, stats->other_stack, ANY_PUSH);
	if (stats->remainables_ptr != NULL)
		*(stats->remainables_ptr) = stats->remainables;
	return (SORTED);
}

static void	one_pushed(t_ctr *tcon, t_stack_status *stats)
{
	sorting_manager(tcon, stats->or, FOUR_ELEMENTS, &stats->remainables);
	if (stats->stack == STACK_A)
	{
		stats->pushed -= moving(tcon, stats->other_stack, ANY_PUSH);
		sorting_manager(tcon, stats->or, TWO_ELEMENTS, &stats->remainables);
	}
	else if (stats->stack == STACK_B)
		sorting_manager(tcon, stats->aux, TWO_ELEMENTS, &stats->remainables);
	if (stats->remainables_ptr)
		(*stats->remainables_ptr) += stats->remainables;
	else
		while (stats->pushed)
			stats->pushed -= moving(tcon, stats->other_stack, ANY_PUSH);
}

/*
Checks if any at the top can be pushed -- return to call 4-sorter.
	Else, if deeper buried on larger (sub) stack, pushes both extremes to aux.
	Else, check if empty-stack (cheap - RRRs possible), calls helper.
*/
static int	displace_elements(t_ctr *tcon, t_stack_status *stats, int r[5])
{
	if (r[1] <= 1)
		moving(tcon, stats->stack, SS);
	if ((r[0] <= 1 || r[1] <= 1) && stats->stack == STACK_B)
		stats->remainables++;
	if (r[0] <= 1 || r[1] <= 1)
		return (stats->pushed += moving(tcon, stats->stack, ANY_PUSH));
	if (stats->or_is_sub_stack)
	{
		while (r[stats->rotated] > 1)
			stats->rotated += moving(tcon, stats->stack, RR);
		stats->pushed += moving(tcon, stats->stack, ANY_PUSH);
		if (r[stats->rotated + 2] <= 1 && (stats->rotated + 2) < 5)
			moving(tcon, stats->stack, SS);
		stats->pushed += moving(tcon, stats->stack, ANY_PUSH);
		if (stats->stack == STACK_B)
			stats->remainables += 2;
		while (stats->rotated)
			stats->rotated -= moving(tcon, stats->stack, RRR);
		return (stats->pushed);
	}
	return (displacement_helper(tcon, stats, r));
}

/*
Function called to help if elements are burried in a larger (sub) stack.
*/
static int	displacement_helper(t_ctr *tcon, t_stack_status *stats, int r[5])
{
	stats->rotated -= moving(tcon, stats->stack, RRR);
	if (r[4] <= 1)
		stats->pushed += moving(tcon, stats->stack, ANY_PUSH);
	else
		stats->rotated -= moving(tcon, stats->stack, RRR);
	stats->rotated -= moving(tcon, stats->stack, RRR);
	if (r[3] <= 1)
		stats->pushed += moving(tcon, stats->stack, ANY_PUSH);
	else
		stats->rotated -= moving(tcon, stats->stack, RRR);
	if (r[2] <= 1)
		stats->pushed += moving(tcon, stats->stack, ANY_PUSH);
	if (stats->stack == STACK_B)
		stats->remainables += 2;
	return (stats->pushed);
}

static int	topextremes_situation(t_ctr *tcon, t_stack_status *stats, int r[5])
{
	if (r[0] > r[1])
	{
		moving(tcon, stats->stack, SS);
		if (r[2] == 2 && r[3] == 3 && r[4] == 4)
			return (SORTED);
	}
	stats->pushed += moving(tcon, stats->stack, ANY_PUSH);
	stats->pushed += moving(tcon, stats->stack, ANY_PUSH);
	sorting_manager(tcon, stats->or, THREE_ELEMENTS, NULL);
	if (stats->stack == STACK_A || !stats->remainables_ptr)
	{
		moving(tcon, stats->other_stack, ANY_PUSH);
		moving(tcon, stats->other_stack, ANY_PUSH);
	}
	else if (stats->remainables_ptr) // so added this check
		(*stats->remainables_ptr) += stats->pushed;
	return (SORTED);
}
