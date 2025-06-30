/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_node.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:53:17 by kasherif          #+#    #+#             */
/*   Updated: 2025/04/25 18:53:17 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_NODE_H
# define LINKED_LIST_NODE_H

# include "push_swap.h"


typedef struct s_node_statistics
{
	int		sub_stack_size;
	int		pos_in_stack;
	int		relative_value;		// variable - relative to stack's current situation 
	int		relative_value_rev;		// variable - relative to stack's current situation 
	char	off_by;					// variable
	char	off_by_rev;				// variable
	char	in_which_quarter;		// variable
	char	in_which_tenth;			// variable
	char	belongs_in_quarter;		// static
	char	belongs_in_quarter_rev;	// static
	char	belongs_in_tenth;		// static
	char	belongs_in_tenth_rev;	// static
	t_mv_q	*rotate;				// misschien wil ik die hier ook? // queue for joint rotation	|| NONE | 
	t_mv_q	*rotate_rev;			// queue for joint reverse rotation
	t_mv_q	*swap;				// queue for joint swap 
}	t_node_stats;

typedef struct s_stack_node
{
	int					actual_value;			// static
	int					normalized_value;		// static
	int					normalized_value_rev;	// static
	t_stack				lives_in_stack;		// stores current location (A or B)
	t_stack				other_stack;		// stores current location (A or B)
	int					*stack_size_a;		// points to tcon's info on stack a
	int					*stack_size_b;		// points to tcon's info on stack b
	int					*this_stack_size;	// depends on current location
	int					*other_stack_size;	// depends on current location
	t_mv_q				rotate;				// queue for joint rotation	|| NONE | 
	t_mv_q				rotate_rev;			// queue for joint reverse rotation
	t_mv_q				swap;				// queue for joint swap 
	t_node_stats		n_stats;
	// t_node_stats		n_sub_stats;
	struct s_stack_node	*next;				// points upwards (top->next == bot)
	struct s_stack_node	*previous;			// points downwards (bottom->previous == top)
}	t_n;

#endif
