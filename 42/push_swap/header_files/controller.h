/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:02:56 by kasherif          #+#    #+#             */
/*   Updated: 2025/04/25 17:02:56 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
# define CONTROLLER_H

# include "push_swap.h"

typedef struct s_stack_status
{
	t_n *const *or;
	t_n *const *aux;
	t_n *const *s_a;
	t_n *const *s_b;
	
	t_stack		stack;
	t_stack		other_stack;

	int			stack_size;
	int			other_size;
	int			*norm_arr;
	int			*norm_rev;
	int			or_is_sub_stack;
	int			aux_is_sub_stack;

	// movements requirements
	int			pushed;
	int			rotated;
	int			aux_rred;
	int			origin_rred;
	int			remainables;
	int			*remainables_ptr;

	// update_meta
	int			perc_sorted;
	int			perc_sorted_rev;
	int			perc_sorted_off_by_max_2;
	int			perc_sorted_off_by_max_2_rev;
	int			perc_in_quarter_bucket;
	int			perc_in_quarter_bucket_rev;
	int			perc_in_tenth_bucket;
	int			perc_in_tenth_bucket_rev;
	
	// other meta
	// bucket_sort requirements
	int			bucket_size;
	int			bucket_zero;
	int			bucket_one;
	int			bucket_two;
	int			bucket_two_total;
	int			bucket_three;
	int			bot_starters;
	int			parked_3s[3];
	int			*bucket_arr;

	// quick_sort requirements
	int			max_value;
	int			min_value;
	int			pivot_point;

	// insertion
	int			outliers_fwd;
	int			outliers_rev;

}	t_stack_status;

typedef struct s_controller
{
	int					total_elements;
	int					*nbr_arr;
	int					*norm_arr;
	int					stack_size_a;
	int					stack_size_b;
	int					stack_status;
	t_n					*a_top;
	t_n					*a_bottom;
	t_n					*b_top;
	t_n					*b_bottom;
	t_mv_q				*a_rotate;
	t_mv_q				*a_rotate_rev;
	t_mv_q				*a_swap;
	t_mv_q				*b_rotate;
	t_mv_q				*b_rotate_rev;
	t_mv_q				*b_swap;
	t_stack_status		global_stats;
	// t_stack_status		sub_stats;	// may be fased out
	char				a_ss_possible;
	char				b_ss_possible;
	char				a_rr_possible;
	char				b_rr_possible;
	char				a_rrr_possible;
	char				b_rrr_possible;	
	int					count_of_moves;
}	t_ctr;

#endif

/*
Misschien een enum voor een kleine future moves sequence
b_rrr_possible;		NO, YES, YES_IN_TWO 
oid?
*/

// 	// t_algo				selected_algo;
// 	t_n					**stack_arr;		// indexed by normalized values
// 	int					pivot_point_stack_general;	// static number - higher mid-value in case of even stack 
// 	int					pivot_point_stack_a;		// variable (updated continuously) - higher mid-value in case of even stack 
// 	int					pivot_point_stack_b;
// 	char				which_rotation;				// tracks how manyth rotation
// 	char				which_rotation_this_algo;
// 	char				stack_status; // want to keep?? No?	// SORTED, REV_SORTED, UNSORTED, (or a mess?) maybe %%
// 	char				a_ss_possible;
// 	char				b_ss_possible;
// 	char				**temp_words;
// }	t_ctr;

