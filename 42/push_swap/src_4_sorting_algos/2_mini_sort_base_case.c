/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_mini_sort_base_case.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:25:11 by kasherif          #+#    #+#             */
/*   Updated: 2025/03/18 11:25:11 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

int			mini_sort(t_ctr *tcon, t_stack_status *stats);
int			*get_ranks(t_stack stack, const int *values, int *ranks, int size);
static int	more_extreme(t_stack stack, int a, int b);
int			find_rank_index(const int *ranks, int size, int target);

/*
Function only called upon if user-input was 1 - 5 elements.
*/
int	mini_sort(t_ctr *tcon, t_stack_status *stats)
{
	if (stats->stack_size == 2)
		return (two_element_sort(tcon, stats));
	if (stats->stack_size == 3)
	{
		if (stats->stack == STACK_A)
			return (three_element_sort(tcon, stats, stats->norm_arr));
		if (stats->stack == STACK_B)
			return (three_element_sort(tcon, stats, stats->norm_rev));
	}
	if (stats->stack_size == 4)
	{
		if (stats->stack == STACK_A)
			return (four_element_sort(tcon, stats, stats->norm_arr));
		if (stats->stack == STACK_B)
			return (four_element_sort(tcon, stats, stats->norm_rev));
	}
	if (stats->stack_size == 5)
	{
		if (stats->stack == STACK_A)
			return (five_element_sort(tcon, stats, stats->norm_arr));
		if (stats->stack == STACK_B)
			return (five_element_sort(tcon, stats, stats->norm_rev));
	}
	return (INVALID);
}

/*
Helper function. Ranks the members of the passed array, to help the caller 
	uncover the extreme or two extremes in the sub-stack.
*/
int	*get_ranks(t_stack stack, const int *values, int *ranks, int size)
{
	int	i;
	int	j;
	int	rank;

	i = -1;
	while (++i < size)
	{
		rank = 0;
		j = -1;
		while (++j < size)
			if (j != i && more_extreme(stack, values[j], values[i]))
				rank++;
		ranks[i] = rank;
	}
	return (ranks);
}

static int	more_extreme(t_stack stack, int a, int b)
{
	if (stack == STACK_A)
		return (a < b);
	return (a > b);
}

/*
Helper function, only used in the five_element_sorter
*/
int	find_rank_index(const int *ranks, int size, int target)
{
	int	i;

	i = -1;
	while (++i < size)
		if (ranks[i] == target)
			return (i);
	return (INVALID);
}
