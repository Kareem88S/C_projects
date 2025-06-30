/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_two_off.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:04:36 by kasherif          #+#    #+#             */
/*   Updated: 2025/06/24 09:58:21 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

#define FIVE 5

int			max_two_off(t_ctr *tcon, t_stack_status *stats);
// static void	rotate_last_five(t_ctr *tcon, t_n *const *top_or);
// static void	clear_the_way(t_ctr *tcon, t_n *const *top_or, int in_the_way);
// static void	reverse_rotate_all(t_ctr *tcon, t_n *const *top_or, int size);

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
	int	i;

	i = -1;
	while (++i < (stats->stack_size - FIVE))
	{
		if (((i % 3) == 0) && (i < (stats->stack_size - FIVE)))
			sorting_manager(tcon, stats->or, FIVE, NULL);
		stats->pushed += moving(tcon, stats->stack, ANY_PUSH);
	}
	sorting_manager(tcon, stats->or, FIVE, NULL);
	while (stats->pushed)
		stats->pushed -= moving(tcon, stats->other_stack, ANY_PUSH);


	// if (stats->or_is_sub_stack == 0)
	// 	rotate_last_five(tcon, stats->or);
	// else if ((stats->or_is_sub_stack + FIVE) < (stats->stack_size - FIVE))
	// 	clear_the_way(tcon, stats->or, stats->or_is_sub_stack);
	// else
	// 	reverse_rotate_all(tcon, stats->or, stats->stack_size);
	return (SORTED);
}
// int	max_two_off(t_ctr *tcon, t_stack_status *stats)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < (stats->stack_size - FIVE))
// 	{
// 		if (((i % 3) == 0) && (i < (stats->stack_size - FIVE)))
// 			sorting_manager(tcon, stats->or, FIVE, NULL);
// 		moving(tcon, stats->stack, RR);
// 	}
// 	sorting_manager(tcon, stats->or, FIVE, NULL);
// 	if (stats->or_is_sub_stack == 0)
// 		rotate_last_five(tcon, stats->or);
// 	else if ((stats->or_is_sub_stack + FIVE) < (stats->stack_size - FIVE))
// 		clear_the_way(tcon, stats->or, stats->or_is_sub_stack);
// 	else
// 		reverse_rotate_all(tcon, stats->or, stats->stack_size);
// 	return (SORTED);
// }

// static void	reverse_rotate_all(t_ctr *tcon, t_n *const *top_or, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size - FIVE)
// 	{
// 		moving(tcon, (*top_or)->lives_in_stack, RRR);
// 		i++;
// 	}
// }

// static void	clear_the_way(t_ctr *tcon, t_n *const *top_or, int in_the_way)
// {
// 	int	i;

// 	i = 0;
// 	while (i < (in_the_way + FIVE))
// 	{
// 		moving(tcon, (*top_or)->lives_in_stack, RR);
// 		i++;
// 	}
// }

// static void	rotate_last_five(t_ctr *tcon, t_n *const *top_or)
// {
// 	int	i;

// 	i = 0;
// 	while (i < FIVE)
// 	{
// 		moving(tcon, (*top_or)->lives_in_stack, RR);
// 		i++;
// 	}
// 	return ;
// }



// int	max_two_off(t_ctr *tcon, t_stack_status *stats)
// {
// 	t_n	*node;
// 	int	outliers;
// 	int	i;
// 	int	j;

// 	node = (*stats->or);
// 	outliers = 0;
// 	i = -1;
// 	while (++i < (stats->stack_size - FIVE))
// 	{
// 		j = i - outliers;
// 		if (abs(node->n_stats.off_by) > 2)
// 		{
// 			outliers++;
// 			moving(tcon, stats->stack, ANY_PUSH);
// 			continue ;
// 		}
// 		if (((j % 3) == 0) && (i < (stats->stack_size - FIVE)))	// <-- check last 5 for outliers
// 			sorting_manager(tcon, stats->or, FIVE, NULL);
// 		moving(tcon, stats->stack, RR);
// 		node = node->previous;
// 	}
// 	if (outliers)
// 		sorting_manager(tcon, stats->aux, outliers, NULL);


// 	sorting_manager(tcon, stats->or, FIVE, NULL);
// 	if (!stats->or_is_sub_stack)
// 		rotate_last_five(tcon, stats->or);
// 	else if ((stats->or_is_sub_stack + FIVE) < (stats->stack_size - FIVE))
// 		clear_the_way(tcon, stats->or, stats->or_is_sub_stack);
// 	else
// 		reverse_rotate_all(tcon, stats->or, stats->stack_size);
// 	return (SORTED);
// }