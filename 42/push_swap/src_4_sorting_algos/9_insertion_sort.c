/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_insertion_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:04:36 by kasherif          #+#    #+#             */
/*   Updated: 2025/07/07 17:49:53 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

#define FIVE 5

int			insertion_max_two_off(t_ctr *tcon, t_stack_status *stats);
static int	seperate_outliers(t_ctr *tcon, t_stack_status *stats);
static void	sort_outliers(t_ctr *tcon, t_stack_status *stats, int outliers);
static int	fuse_elements_stack_A(t_ctr *tcon, t_stack_status *stats);
static int	move_sorted_out_of_the_way(t_ctr *tcon, t_stack_status *stats, int outliers);
static int	fuse_elements_stack_B(t_ctr *tcon, t_stack_status *stats, int outliers);

/*
function called only when stack is mostly sorted, but contains few outliers.
*/
int	insertion_max_two_off(t_ctr *tcon, t_stack_status *stats)
{
	int	outliers;

	outliers = seperate_outliers(tcon, stats);
	sort_outliers(tcon, stats, outliers);
	if (stats->stack == STACK_A)
	{
		fuse_elements_stack_A(tcon, stats);
		sorting_manager(tcon, stats->or, FIVE, NULL);
		sorting_manager(tcon, stats->or, stats->stack_size, NULL);
	}
	else
	{
		move_sorted_out_of_the_way(tcon, stats, outliers);
		fuse_elements_stack_B(tcon, stats, outliers);
		sorting_manager(tcon, stats->aux, FIVE, NULL);
		sorting_manager(tcon, stats->aux, stats->stack_size, NULL);
	}
	return (SORTED);
}


/*
Applies only if stack B is the origin stack
*/
static int	move_sorted_out_of_the_way(t_ctr *tcon, t_stack_status *stats, int outliers)
{
	int			i;
	t_n *const	*a = stats->aux;
	t_n *const	*b = stats->or;

	i = -1;
	while (++i < stats->stack_size && i <= outliers
		&& ((*a)->normalized_value < (*b)->normalized_value))
		stats->rotated += moving(tcon, stats->stack, RR);
	return (stats->rotated);
}

static int	fuse_elements_stack_B(t_ctr *tcon, t_stack_status *stats, int outliers)
{
	int	i;
	int	sorted_laggers;

	stats->pushed = outliers;
	sorted_laggers = stats->stack_size - (stats->pushed + stats->rotated);
	i = -1;
	while (((stats->pushed + stats->rotated) > 0) && (++i > -1))
	{
		if ((i % 3 == 0) && ((i >= FIVE) || (sorted_laggers >= FIVE)))
			sorting_manager(tcon, stats->aux, FIVE, NULL);
		if (!stats->pushed)
			stats->rotated -= moving(tcon, stats->other_stack, RRR);
		else if (!stats->rotated)
			stats->pushed -= moving(tcon, stats->stack, ANY_PUSH);
		else if ((*stats->or)->normalized_value
			< (*stats->aux)->next->normalized_value)
			stats->pushed -= moving(tcon, stats->other_stack, ANY_PUSH);
		else
			stats->rotated -= moving(tcon, stats->stack, RRR);
	}
	return (SORTED);
}

static int	fuse_elements_stack_A(t_ctr *tcon, t_stack_status *stats)
{
	int	i;

	i = -1;
	while (((stats->pushed + stats->rotated) > 0) && (++i > -1))
	{
		if ((i % 3 == 0) && i >= FIVE)
			sorting_manager(tcon, stats->or, FIVE, NULL);
		if (!stats->pushed)
			stats->rotated -= moving(tcon, stats->stack, RRR);
		else if (!stats->rotated)
			stats->pushed -= moving(tcon, stats->other_stack, ANY_PUSH);
		else if ((*stats->or)->next->normalized_value
			< (*stats->aux)->normalized_value)
			stats->pushed -= moving(tcon, stats->other_stack, ANY_PUSH);
		else
			stats->rotated -= moving(tcon, stats->stack, RRR);
	}
	return (SORTED);
}

static int	seperate_outliers(t_ctr *tcon, t_stack_status *stats)
{
	int	outliers;
	int	i;
	int	j;

	outliers = 0;
	i = -1;
	while (++i < (stats->stack_size))
	{
		j = i - outliers;
		if (abs((*stats->or)->n_stats.off_by) > 2 && ++outliers)
		{
			stats->rotated += moving(tcon, stats->stack, RR);
			if (((j % 3) == 0) && (j >= FIVE))
				sorting_manager(tcon, stats->aux, FIVE, NULL);		
		}
		else
			stats->pushed += moving(tcon, stats->stack, ANY_PUSH);
	}
	return (outliers);
}

static void	sort_outliers(t_ctr *tcon, t_stack_status *stats, int outliers)
{
	int	i;
	
	i = -1;
	while (stats->or_is_sub_stack && ++i < outliers)
		stats->rotated -= moving(tcon, stats->stack, RRR);
	if (outliers)
		sorting_manager(tcon, stats->or, outliers, NULL);
	if (stats->stack == STACK_A)
	{
		i = -1;
		while (stats->or_is_sub_stack && ++i < outliers)
			stats->rotated += moving(tcon, stats->stack, RR);
	}
}