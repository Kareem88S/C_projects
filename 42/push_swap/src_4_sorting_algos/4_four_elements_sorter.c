/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_four_elements_sorter.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:28:52 by kasherif          #+#    #+#             */
/*   Updated: 2025/04/20 20:55:00 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

int			four_element_sort(t_ctr *tcon, t_stack_status *stats, int *ranks);
static void	four_element_helper(t_ctr *tcon, t_stack_status *s, int *ranks);

#define THREE_ELEMENTS 3
#define EXTREME 0

/*
Checks if the top-element(s) are extremes (cheaper).
	If the sorting stack is stack B, the pushed-into-A element will remain there
	Otherwise it will be returned after the 3-element-sorter completes.
If the extreme is buried deeper, functionallity is outsourced to helper.
*/
int	four_element_sort(t_ctr *tcon, t_stack_status *s, int *ranks)
{
	if (ranks [0] == 1 && ranks[1] == 0 && s->perc_sorted == 50)
		return (moving(tcon, s->stack, SS), SORTED);
	if (ranks[0] == EXTREME || ranks[1] == EXTREME)
	{
		if (ranks[1] == EXTREME)
			moving(tcon, s->stack, SS);
		if (s->stack == STACK_A)
			s->rotated += moving(tcon, s->stack, RR);
		if (s->stack == STACK_B)
		{
			(*s->remainables_ptr)++;
			s->pushed += moving(tcon, s->stack, ANY_PUSH);
		}
		sorting_manager(tcon, s->or, THREE_ELEMENTS, NULL);
		if (s->rotated)
			s->rotated -= moving(tcon, s->stack, RRR);
		return (SORTED);
	}
	four_element_helper(tcon, s, ranks);
	return (SORTED);
}

/*
Handles burried element. Function divided into two sections:
	- is substack (more expensive in terms of RRs and RRRs)
	- is not substack (few RRR(s) will suffice)
*/
static void	four_element_helper(t_ctr *tcon, t_stack_status *s, int *ranks)
{
	if (!s->or_is_sub_stack)
	{
		if (ranks[2] == EXTREME)
			s->rotated -= moving(tcon, s->stack, RRR);
		sorting_manager(tcon, s->or, THREE_ELEMENTS, s->remainables_ptr);
		s->rotated -= moving(tcon, s->stack, RRR);
	}
	else if (s->or_is_sub_stack)
	{
		while (ranks[s->rotated] > EXTREME)
			s->rotated += moving(tcon, s->stack, RR);
		s->pushed += moving(tcon, s->stack, ANY_PUSH);
		if (s->stack == STACK_B)
			(*s->remainables_ptr)++;
		while (s->rotated)
			s->rotated -= moving(tcon, s->stack, RRR);
		sorting_manager(tcon, s->or, THREE_ELEMENTS, s->remainables_ptr);
		if (*s->remainables_ptr == 0)
			s->pushed -= moving(tcon, s->other_stack, ANY_PUSH);
	}
	return ;
}
