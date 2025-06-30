/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_sorting_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:48:49 by kasherif          #+#    #+#             */
/*   Updated: 2025/02/26 12:48:49 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

int			sorting_manager(t_ctr *tcon, t_n *const *top_orig,
				int cur_stack_size, int *dont_push);
static int	sorting_algos(t_ctr *tcon, t_stack_status *stats);




int	sorting_manager(t_ctr *tcon, t_n *const *top_orig,
				int cur_stack_size, int *dont_push)
{
	t_stack const	stack = (*top_orig)->lives_in_stack;
	t_stack_status	stats;

	ft_bzero(&stats, sizeof(t_stack_status));
	stats.s_a = &(tcon->a_top);
	stats.s_b = &(tcon->b_top);
	stats.or = top_orig;
	if ((*top_orig)->lives_in_stack == STACK_A)
		stats.aux = &(tcon->b_top);
	else if ((*top_orig)->lives_in_stack == STACK_B)
		stats.aux = &(tcon->a_top);
	stats.remainables = 0;
	stats.remainables_ptr = dont_push;
	if (dont_push != NULL)
		stats.remainables = *dont_push;
	stats.stack_size = cur_stack_size;
	if (update_sub_state(&stats) == INVALID)
		return (free_and_null((void *)&(stats.norm_rev)),
			free_and_null((void *)&(stats.norm_rev)), (INVALID));
	if ((stack == STACK_A && stats.perc_sorted != 100)
		|| (stack == STACK_B && stats.perc_sorted_rev != 100))
		sorting_algos(tcon, &stats);
	free_and_null((void *)&(stats.norm_rev));
	free_and_null((void *)&(stats.norm_arr));
	return (SORTED);
}

static int	sorting_algos(t_ctr *tcon, t_stack_status *stats)
{
	if (stats->stack_size <= 5)
		return (mini_sort(tcon, stats));
	if (stats->stack_size > 5 && stats->stack_size <= 10)
		return (quick_sort(tcon, stats));



	if ((stats->stack == STACK_A && stats->perc_sorted_off_by_max_2_rev >= 100)
		|| (stats->stack == STACK_B
			&& stats->perc_sorted_off_by_max_2_rev >= 100))
		return (reverse_sort(tcon, stats));
	if (stats->stack_size < 80 && ((stats->perc_sorted_off_by_max_2_rev >= 85
			&& stats->stack == STACK_A) || (stats->stack == STACK_B 
				&& stats->perc_sorted_off_by_max_2_rev >= 85)))
		return (reverse_sort(tcon, stats));
	


	// 	if ((stats->stack == STACK_A && stats->perc_sorted_off_by_max_2 >= 100)
	// 	|| (stats->stack == STACK_B
	// 		&& stats->perc_sorted_off_by_max_2 >= 100))
	// 	// return (reverse_sort(tcon, stats));		// max 2 off -- uitzoeken welke fn naam
	// 	// // return (max_two_off(tcon, stats));
	// if (((stats->perc_sorted_off_by_max_2 >= 85 && stats->stack == STACK_A)
	// 		|| (stats->perc_sorted_off_by_max_2
	// 			&& stats->stack == STACK_B >= 85)) && stats->stack_size < 80)
	// 	// return (reverse_sort(tcon, stats));
	// 	// // return (insertion_max_two_off(tcon, stats));

	if (stats->stack_size)
		return (quick_sort(tcon, stats));
	return (SORTED);
}
