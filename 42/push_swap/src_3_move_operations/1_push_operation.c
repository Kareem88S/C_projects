/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:31:03 by kasherif          #+#    #+#             */
/*   Updated: 2025/03/08 18:31:03 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

t_mv		push_move(t_ctr *tcon, t_mv cmd);
static void	push_x_to_y(t_n **top_x, t_n **top_y, t_n **bottom_x, t_n **bottom_y);
static t_n	*remove_top_node(t_n **top, t_n **bottom);
static void	insert_at_top(t_n **top, t_n *node, t_n **bottom);
static void	switch_living_stack(t_ctr *tcon, t_n *top_node);

/*
pa (push a): Take the first element at the top of b and put it at the top of a.
					Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
					Do nothing if a is empty.
*/

t_mv	push_move(t_ctr *tcon, t_mv cmd)
{
	if (cmd == PA && !tcon->b_top)
		return (NO_ACTION_PERFORMED);
	if (cmd == PB && !tcon->a_top)
		return (NO_ACTION_PERFORMED);
	if (cmd == PB)
	{
		print_operation(cmd);
		push_x_to_y(&(tcon->a_top), &(tcon->b_top),
			&(tcon->a_bottom), &(tcon->b_bottom));
		switch_living_stack(tcon, tcon->b_top);
	}
	if (cmd == PA)
	{
		print_operation(cmd);
		push_x_to_y(&(tcon->b_top), &(tcon->a_top),
			&(tcon->b_bottom), &(tcon->a_bottom));
		switch_living_stack(tcon, tcon->a_top);
	}
	return (cmd);
}

/*
moves x to top of y
if only one element in origin
	set origin and linkeage to NULL
else if multiple elements in origin
	relink neighbors
if only element in dest,
	link to self
else
	link neighbors
*/
static void	push_x_to_y(t_n **top_x, t_n **top_y, t_n **bottom_x, t_n **bottom_y)
{
	t_n *popped;

	popped = remove_top_node(top_x, bottom_x);
	insert_at_top(top_y, popped, bottom_y);
}

/*
removes and relinks neighbors
*/
static t_n	*remove_top_node(t_n **top, t_n **bottom)
{
	t_n	*popped;

	popped = *top;
	if ((*top)->next == *top)
	{
		*top = NULL;
		*bottom = NULL;
	}
	else
	{
		(*top)->previous->next = (*top)->next;
		(*top)->next->previous = (*top)->previous;
		if (*bottom == popped)
			*bottom = (*top)->previous;
		*top = (*top)->previous;
	}
	return (popped);
}

/*
inserts, links, and relinks neighbors
*/
static void	insert_at_top(t_n **top, t_n *node, t_n **bottom)
{
	if (!*top)
	{
		*top = node;
		*bottom = node;
		(*top)->next = *top;
		(*top)->previous = *top;
	}
	else
	{
		node->next = (*top)->next;
		node->previous = *top;
		(*top)->next = node;
		node->next->previous = node;
		*top = node;
	}
}

/*
Node was pushed to the other stack. 
This fn updates the fields to match the new location.
*/
static void	switch_living_stack(t_ctr *tcon, t_n *top_node)
{
	if (top_node->lives_in_stack == STACK_A)
	{
		top_node->lives_in_stack = STACK_B;
		top_node->other_stack = STACK_A;
		tcon->stack_size_a--;
		tcon->stack_size_b++;
		top_node->this_stack_size = &(tcon->stack_size_b);
		top_node->other_stack_size = &(tcon->stack_size_a);
	}
	else if (top_node->lives_in_stack == STACK_B)
	{
		top_node->lives_in_stack = STACK_A;
		top_node->other_stack = STACK_B;
		tcon->stack_size_b--;
		tcon->stack_size_a++;
		top_node->this_stack_size = &(tcon->stack_size_a);
		top_node->other_stack_size = &(tcon->stack_size_b);
	}
}
