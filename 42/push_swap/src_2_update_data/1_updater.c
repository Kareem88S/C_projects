/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_updater.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 11:45:07 by kasherif          #+#    #+#             */
/*   Updated: 2025/06/30 13:40:11 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

#define QUARTS 4
#define TENTHS 10

// updater_helper.c
void		update_meta(t_stack_status *s);

// updater_helper_2.c
void		get_outliers(t_stack_status *s);

// this file
int			update_global_state(t_ctr *tcon);
int			update_sub_state(t_stack_status *stats);
static int	build_section_arrays(t_stack_status *section, t_n *node, int size);
static void	update_nodes(t_stack_status *s);
static void	get_off_by_position(t_stack_status *s);

int	update_global_state(t_ctr *tcon)
{
	t_stack_status	*g_s;

	g_s = &(tcon->global_stats);
	if (tcon->a_top == NULL || tcon->b_top != NULL)
		return (INVALID);
	g_s->stack_size = tcon->stack_size_a;
	g_s->other_size = 0;
	g_s->or = &(tcon->a_top);
	g_s->aux = &(tcon->b_top);
	g_s->stack = STACK_A;
	g_s->other_stack = STACK_B;
	g_s->or_is_sub_stack = 0;
	g_s->aux_is_sub_stack = 0;
	g_s->norm_rev = malloc(sizeof(int) * tcon->stack_size_a);
	g_s->norm_arr = malloc(sizeof(int) * tcon->stack_size_a);
	if (!g_s->norm_rev || !g_s->norm_arr || INVALID
		== build_section_arrays(g_s, *(g_s->or), tcon->stack_size_a))
		return (free_and_null((void *)&(g_s->norm_arr)),
			free_and_null((void *)&(g_s->norm_rev)), INVALID);
	update_nodes(g_s);
	update_meta(g_s);
	free_and_null((void *)&(g_s->norm_arr));
	free_and_null((void *)&(g_s->norm_rev));
	return (VALID);
}

int	update_sub_state(t_stack_status *stats)
{
	int const	sub_size = stats->stack_size;

	stats->other_size = 0;
	if ((*stats->aux))
		stats->other_size = *((*stats->aux)->this_stack_size);
	stats->stack = (*stats->or)->lives_in_stack;
	stats->other_stack = (*stats->or)->other_stack;
	stats->or_is_sub_stack = *(*(stats->or))->this_stack_size - sub_size;
	stats->aux_is_sub_stack = stats->other_size;
	stats->norm_rev = malloc(sizeof(int) * sub_size);
	stats->norm_arr = malloc(sizeof(int) * sub_size);
	if (!stats->norm_rev || !stats->norm_arr)
		return (free_and_null((void *)&(stats->norm_rev)),
			free_and_null((void *)&(stats->norm_arr)), INVALID);
	if (build_section_arrays(stats, *(stats->or), sub_size) == INVALID)
		return (free_and_null((void *)&(stats->norm_rev)),
			free_and_null((void *)&(stats->norm_arr)), INVALID);
	update_nodes(stats);
	update_meta(stats);
	return (VALID);
}

/*
builds a temp array in which the normalized values are stored. 
Then copies the temp array's values over into the struct-array
Then reverse-copies these results into the struct's reverse-array
If anything fails along the way, the 'fail-safe' will block further advancements
*/
static int	build_section_arrays(t_stack_status *section, t_n *node, int size)
{
	int	*temp_arr;
	int	i;
	int	fail_safe;

	temp_arr = malloc(sizeof(int) * size);
	if (!temp_arr)
		return (INVALID);
	i = -1;
	while (++i < size)
	{
		temp_arr[i] = node->normalized_value;
		node = node->previous;
	}
	fail_safe = normalize_array(section->norm_arr, temp_arr, size);
	i = -1;
	while (++i < size && fail_safe != INVALID)
		section->norm_rev[i] = size - 1 - section->norm_arr[i];
	free_and_null((void *)&(temp_arr));
	return (fail_safe);
}


static void	update_nodes(t_stack_status *s)
{
	int	index;
	t_n	*n;
	int	rel_val;
	int	rel_rev;

	n = *(s->or);
	index = -1;
	while (++index < s->stack_size)
	{
		rel_val = s->norm_arr[index];
		rel_rev = s->norm_rev[index];
		n->n_stats.sub_stack_size = s->stack_size;
		n->n_stats.pos_in_stack = index;
		n->n_stats.relative_value = rel_val;
		n->n_stats.relative_value_rev = rel_rev;
		n->n_stats.belongs_in_quarter = (rel_val * QUARTS) / s->stack_size;
		n->n_stats.belongs_in_quarter_rev = (rel_rev * QUARTS) / s->stack_size;
		n->n_stats.belongs_in_tenth = (rel_val * TENTHS) / s->stack_size;
		n->n_stats.belongs_in_tenth_rev = (rel_rev * TENTHS) / s->stack_size;
		n->n_stats.in_which_quarter = (index * QUARTS) / s->stack_size;
		n->n_stats.in_which_tenth = (index * TENTHS) / s->stack_size;
		n = n->previous;
	}
	get_off_by_position(s);
}



// static void	get_off_by_position(t_stack_status *s)
void	get_outliers(t_stack_status *s)
{
	int 			i;
	t_n				*cur;
	t_node_stats	n_s;

	i = -1;
	cur = *(s->or);
	s->outliers_fwd = 0;
	s->outliers_rev = 0;
	if (s->stack_size > 80)
		return ;
	while (++i < s->stack_size)
	{
		n_s = cur->n_stats;
		if (s->stack_size < 20)
		{
			if (n_s.in_which_quarter != n_s.belongs_in_quarter)
				s->outliers_fwd++;
			else if (n_s.in_which_tenth < n_s.belongs_in_tenth - 1
				|| n_s.in_which_tenth > n_s.belongs_in_tenth + 1)
				s->outliers_fwd++;
			if (n_s.in_which_quarter != n_s.belongs_in_quarter_rev)
				s->outliers_rev++;
			else if (n_s.in_which_tenth < n_s.belongs_in_tenth_rev - 1
				|| n_s.in_which_tenth > n_s.belongs_in_tenth_rev + 1)
				s->outliers_rev++;
		}
		else if (s->stack_size <= 80)
		{
			if (n_s.in_which_tenth != n_s.belongs_in_tenth)
			s->outliers_fwd++;
		if (n_s.in_which_tenth != n_s.belongs_in_tenth_rev)
				s->outliers_rev++;
		}
		cur = cur->previous;
	}
}

	
static void	get_off_by_position(t_stack_status *s)
{
	int		i;
	t_n		*cur;

	get_outliers(s);


	i = -1;
	cur = *(s->or);
	s->outliers_fwd = 0;
	s->outliers_rev = 0;
	while (++i < s->stack_size)
	{
		if ((i < s->stack_size - 1) && (cur->n_stats.relative_value - cur->previous->n_stats.relative_value >= -5)
			&& (cur->n_stats.relative_value - cur->previous->n_stats.relative_value <= 3))
			s->outliers_fwd++;
		else if (i == s->stack_size - 1)

		if ((i < s->stack_size - 1) && (cur->n_stats.relative_value_rev - cur->previous->n_stats.relative_value_rev >= -5)
			&& (cur->n_stats.relative_value_rev - cur->previous->n_stats.relative_value_rev <= 3))
			

		cur->n_stats.off_by_rev = cur->n_stats.relative_value_rev - s->outliers_rev;
		// cur->n_stats.off_by = cur->n_stats.relative_value - s->outliers_fwd;
		// cur->n_stats.off_by_rev = cur->n_stats.relative_value_rev - s->outliers_rev;
		if (abs(cur->n_stats.off_by) > 2)
			s->outliers_fwd++;
		if (abs(cur->n_stats.off_by_rev) > 2)
			s->outliers_rev++;
		cur = cur->previous;
	}
		// while (++i < s->stack_size)
		// {
		// 	cur->n_stats.off_by = cur->n_stats.relative_value - s->outliers_fwd;
		// 	cur->n_stats.off_by_rev = cur->n_stats.relative_value_rev - s->outliers_rev;
		// 	if (abs(cur->n_stats.off_by) > 2)
		// 		s->outliers_fwd++;
		// 	if (abs(cur->n_stats.off_by_rev) > 2)
		// 		s->outliers_rev++;
		// 	cur = cur->previous;
		// }


		
	// real_index = -1;
	// cur = *(s->or);
	// while (++real_index < s->stack_size)
	// {
	// 	cur->n_stats.off_by -= s->outliers;
	// 	cur->n_stats.off_by_rev -= s->outliers;
	// 	cur = cur->previous;
	// }
}

// static void	get_off_by_position(t_stack_status *s)
// {
// 	int		real_index;
// 	int		adjusted_index;
// 	int		off_by;
// 	int		off_by_rev;
// 	t_n		*cur;

// 	real_index = -1;
// 	adjusted_index = 0;
// 	cur = *(s->or);
// 	s->outliers = 0;
// 	while (++real_index < s->stack_size)
// 	{
// 		off_by = adjusted_index - cur->n_stats.relative_value;
// 		off_by_rev = adjusted_index - cur->n_stats.relative_value_rev;
// 		cur->n_stats.off_by = off_by;
// 		cur->n_stats.off_by_rev = off_by_rev;
// 		if (abs(off_by) > 2 && abs(off_by_rev) > 2)
// 			s->outliers++;
// 		else
// 			adjusted_index++;
// 		cur = cur->previous;
// 	}
// 	// real_index = -1;
// 	// cur = *(s->or);
// 	// while (++real_index < s->stack_size)
// 	// {
// 	// 	cur->n_stats.off_by -= s->outliers;
// 	// 	cur->n_stats.off_by_rev -= s->outliers;
// 	// 	cur = cur->previous;
// 	// }
// }
