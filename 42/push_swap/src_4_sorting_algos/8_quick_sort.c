/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_quick_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:42:07 by kasherif          #+#    #+#             */
/*   Updated: 2025/04/15 12:42:07 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

int			quick_sort(t_ctr *tcon, t_stack_status *s);
static void	distributor(t_ctr *tcon, t_stack_status *s);
static void	sort_sections(t_ctr *tcon, t_stack_status *s);
static void	check_cheaper_distribution(t_stack_status *s);

/*
First sets meta-data for proper decision-making in the meta struct.
Then divides the stack into two segments: "foundation" elments (big numbers in A
	and small numbers in B) are RR'ed out of the way, "roof" elements are pushed
	to the other stack.
Once all are distributed, the RR'd foundational elements are returned. 
	Three options:
	- 1) either the 'total stack' (excluding our sub-stack) was empty, then
		no further action required, and our foundation is already in place;
	- 2) the 'total stack' was tiny (fewer than the RR'ed), then we continue
		RR'ing the elements out of the way so our foundation resurfaces;
	- 3) the stack is large, and the cheapest way is to RRR the elements back.
Then both are sorted (managed by another function). Once this has succesfully
	finished, the pushed "roof" elements are returned, and the stack is sorted.
*/

/*
First the distributor-function is called: here the stack is split into above-
	pivot and below-pivot.
*/
int	quick_sort(t_ctr *tcon, t_stack_status *s)
{
	int	i;
	int	rotated_elements;

	distributor(tcon, s);
	rotated_elements = s->rotated;
	i = -1;
	while ((s->or_is_sub_stack < s->pivot_point)
		&& (++i < s->or_is_sub_stack))
		s->rotated += moving(tcon, s->stack, RR);
	while ((s->or_is_sub_stack >= s->pivot_point)
		&& rotated_elements)
		rotated_elements -= moving(tcon, s->stack, RRR);
	sort_sections(tcon, s);
	i = -1;
	while ((s->stack == STACK_B)
		&& ((++i + s->remainables) < (s->stack_size / 2)))
		s->pushed += moving(tcon, s->stack, ANY_PUSH);
	if (s->stack == STACK_B)
		(*s->remainables_ptr) = (s->pushed + s->remainables);
	while (s->stack == STACK_A && (s->pushed - s->remainables))
		s->pushed -= moving(tcon, s->other_stack, ANY_PUSH);
	return (SORTED);
}

static void	sort_sections(t_ctr *tcon, t_stack_status *s)
{
	if (s->stack == STACK_A)
	{
		sorting_manager(tcon, s->or, s->rotated, &s->remainables);
		sorting_manager(tcon, s->aux, s->pushed, &s->remainables);
	}
	if (s->stack == STACK_B)
	{
		sorting_manager(tcon, s->aux, s->pushed, &s->remainables);
		sorting_manager(tcon, s->or, s->rotated, &s->remainables);
	}
}

/*
First checks if the working-stack is empty other than the working sortables:
	check if cheaper than standard disro is possible.

*/
static void	distributor(t_ctr *tcon, t_stack_status *s)
{
	int			i;
	t_n *const	*cur_node;

	i = -1;
	if (s->or_is_sub_stack == 0)
		check_cheaper_distribution(s);

	i = -1;
	while (++i < s->stack_size)
	{
		cur_node = s->or;
		if (((s->stack == STACK_A)
				&& ((*cur_node)->n_stats.relative_value >= s->pivot_point))
			|| ((s->stack == STACK_B)
				&& ((*cur_node)->n_stats.relative_value < s->pivot_point)))
			s->rotated += moving(tcon, s->stack, RR);
		else
			s->pushed += moving(tcon, s->stack, ANY_PUSH);
	}
}


static void	check_cheaper_distribution(t_stack_status *s)
{
	int	i;
	int	bottoms_in_upper_half;
	int	bottoms_in_lower_half;
	int bottoms_away_from_bottom;
	int bottoms_away_from_top;

	bottoms_away_from_bottom = 0;
	bottoms_away_from_top = 0;
	bottoms_in_lower_half = 0;
	bottoms_in_upper_half = 0;
	i = -1;
	while (++i < s->pivot_point)
	{
		if ((s->stack == STACK_A && s->norm_arr[i] > s->pivot_point)
			|| (s->stack == STACK_B && s->norm_rev[i] < s->pivot_point))
			bottoms_in_upper_half++;
		else if (i == bottoms_away_from_top)
			bottoms_away_from_top++;
	}
	i = s->stack_size;
	while (--i > s->pivot_point)
	{
		if ((s->stack == STACK_A && s->norm_arr[i] > s->pivot_point)
			|| (s->stack == STACK_B && s->norm_rev[i] < s->pivot_point))
			bottoms_in_lower_half++;
		else if (i == bottoms_away_from_top)
			bottoms_away_from_bottom++;
	}
}