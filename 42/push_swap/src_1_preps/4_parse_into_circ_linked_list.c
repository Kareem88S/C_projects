/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_parse_into_circ_linked_list.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:46:23 by kasherif          #+#    #+#             */
/*   Updated: 2025/04/26 00:46:23 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

int			parse_into_circ_linked_list(t_ctr *tcon);
static int	create_stack_node(t_n **new_node);
static int	populate_node_with_values(t_ctr *tcon, t_n *node, int index);
static void	relink_stack_nodes(t_ctr *tcon, t_n **new_node, t_n *last_set_node);
void		set_static_node_statistics(t_n *node, int stack_size);

/*
Builds top to bottom: first element is top-node. Last is bottom-node.
	Creates nodes for the circular linked list.
		Populates node with the actual value (redundant) and normalized value.
		Links node to its neighbor-nodes.
	Links top and bottom to corresponding fields in the controller-struct.
*/
int	parse_into_circ_linked_list(t_ctr *tcon)
{
	t_n	*last_set_node;
	t_n	*new_node;
	int	index;

	last_set_node = NULL;
	index = -1;
	while (++index < tcon->total_elements)
	{
		if (create_stack_node(&new_node) == INVALID)
			return (error_msg_free_all(tcon), INVALID);
		if (populate_node_with_values(tcon, new_node, index) == INVALID)
			return (error_msg_free_all(tcon), INVALID);
		relink_stack_nodes(tcon, (&new_node), last_set_node);
		last_set_node = new_node;
	}
	tcon->stack_size_a = tcon->total_elements;
	return (VALID);
}

static int	create_stack_node(t_n **new_node)
{
	*new_node = malloc(sizeof(t_n));
	if (!*new_node)
		return (INVALID);
	(*new_node)->actual_value = 0;
	(*new_node)->normalized_value = 0;
	(*new_node)->normalized_value_rev = 0;
	(*new_node)->lives_in_stack = 0;
	(*new_node)->other_stack = 0;
	(*new_node)->stack_size_a = 0;
	(*new_node)->stack_size_b = 0;
	(*new_node)->this_stack_size = 0;
	(*new_node)->other_stack_size = 0;
	(*new_node)->rotate = 0;
	(*new_node)->rotate_rev = 0;
	(*new_node)->swap = 0;
	return (VALID);
}

static int	populate_node_with_values(t_ctr *tcon, t_n *node, int index)
{
	int const	stack_size = tcon->total_elements;
	int			rev_formula;

	node->actual_value = tcon->nbr_arr[index];
	node->normalized_value = tcon->norm_arr[index];
	rev_formula = stack_size - node->normalized_value - 1;
	node->normalized_value_rev = rev_formula;
	node->n_stats.relative_value = node->normalized_value;
	node->n_stats.relative_value_rev = rev_formula;
	set_static_node_statistics(node, stack_size);
	node->lives_in_stack = STACK_A;
	node->other_stack = STACK_B;
	node->stack_size_a = &(tcon->stack_size_a);
	node->stack_size_b = &(tcon->stack_size_b);
	node->this_stack_size = node->stack_size_a;
	node->rotate = NONE;
	node->rotate_rev = NONE;
	node->swap = NONE;
	return (VALID);
}

void	set_static_node_statistics(t_n *node, int stack_size)
{
	int const	relative_val = node->n_stats.relative_value;
	int const	rev_formula = node->n_stats.relative_value_rev;

	node->n_stats.belongs_in_quarter = (relative_val * 4) / stack_size;
	node->n_stats.belongs_in_quarter_rev = (rev_formula * 4) / stack_size;
	node->n_stats.belongs_in_tenth = (relative_val * 10) / stack_size;
	node->n_stats.belongs_in_tenth_rev = (rev_formula * 10) / stack_size;
}

static void	relink_stack_nodes(t_ctr *tcon, t_n **new_node, t_n *last_set_node)
{
	if (!tcon->a_top)
	{
		tcon->a_top = *new_node;
		tcon->a_bottom = *new_node;
		(*new_node)->next = *new_node;
		(*new_node)->previous = *new_node;
	}
	else
	{
		tcon->a_bottom = *new_node;
		tcon->a_bottom->previous = tcon->a_top;
		tcon->a_bottom->next = last_set_node;
		last_set_node->previous = tcon->a_bottom;
		tcon->a_top->next = tcon->a_bottom;
	}
	return ;
}
