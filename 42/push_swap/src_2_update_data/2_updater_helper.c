/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_updater_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 11:45:07 by kasherif          #+#    #+#             */
/*   Updated: 2025/06/27 12:22:12 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

void		update_meta(t_stack_status *s);
static void	count_meta(t_stack_status *s, t_n *node);
static void	preset_meta_to_zero(t_stack_status *s);
static void	calculate_meta(t_stack_status *s, int size);

void	update_meta(t_stack_status *s)
{
	int	index;
	t_n	*current_node;

	current_node = *(s->or);
	preset_meta_to_zero(s);
	index = -1;
	while (++index < s->stack_size)
	{
		count_meta(s, current_node);
		current_node = current_node->previous;
	}
	calculate_meta(s, s->stack_size);
}

static void	count_meta(t_stack_status *s, t_n *node)
{
	if (node->n_stats.off_by == 0)
		s->perc_sorted++;
	if (node->n_stats.off_by_rev == 0)
		s->perc_sorted_rev++;
	if (abs_value(node->n_stats.off_by) <= 2)
		s->perc_sorted_off_by_max_2++;
	if (abs_value(node->n_stats.off_by_rev) <= 2)
		s->perc_sorted_off_by_max_2_rev++;
	if (node->n_stats.in_which_quarter == node->n_stats.belongs_in_quarter)
		s->perc_in_quarter_bucket++;
	if (node->n_stats.in_which_quarter == node->n_stats.belongs_in_quarter_rev)
		s->perc_in_quarter_bucket_rev++;
	if (node->n_stats.in_which_tenth == node->n_stats.belongs_in_tenth)
		s->perc_in_tenth_bucket++;
	if (node->n_stats.in_which_tenth == node->n_stats.belongs_in_tenth_rev)
		s->perc_in_tenth_bucket_rev++;
}

static void	preset_meta_to_zero(t_stack_status *s)
{
	int	i;

	i = 0;
	s->perc_sorted = 0;
	s->perc_sorted_rev = 0;
	s->perc_sorted_off_by_max_2 = 0;
	s->perc_sorted_off_by_max_2_rev = 0;
	s->perc_in_quarter_bucket = 0;
	s->perc_in_quarter_bucket_rev = 0;
	s->perc_in_tenth_bucket = 0;
	s->perc_in_tenth_bucket_rev = 0;
	s->bucket_size = 0;
	s->bucket_zero = 0;
	s->bucket_one = 0;
	s->bucket_two = 0;
	s->bucket_two_total = 0;
	s->bucket_three = 0;
	s->bot_starters = 0;
	while (i < 3)
		s->parked_3s[i++] = 0;
	s->bucket_arr = 0;
	s->max_value = s->stack_size - 1;
	s->min_value = 0;
	s->pivot_point = s->stack_size / 2;
}

static void	calculate_meta(t_stack_status *s, int size)
{
	s->perc_sorted = s->perc_sorted * 100 / size;
	s->perc_sorted_rev = s->perc_sorted_rev * 100 / size;
	s->perc_sorted_off_by_max_2 = s->perc_sorted_off_by_max_2 * 100 / size;
	s->perc_sorted_off_by_max_2_rev
		= s->perc_sorted_off_by_max_2_rev * 100 / size;
	s->perc_in_quarter_bucket = s->perc_in_quarter_bucket * 100 / size;
	s->perc_in_quarter_bucket_rev
		= s->perc_in_quarter_bucket_rev * 100 / size;
	s->perc_in_tenth_bucket = s->perc_in_tenth_bucket * 100 / size;
	s->perc_in_tenth_bucket_rev = s->perc_in_tenth_bucket_rev * 100 / size;
}
