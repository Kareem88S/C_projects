/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_element_sorter.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 03:28:23 by kasherif          #+#    #+#             */
/*   Updated: 2025/05/02 16:36:34 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIVE_ELEMENT_SORTER_H
# define FIVE_ELEMENT_SORTER_H

# include "push_swap.h"

typedef struct	s_five_sorter_meta_data_struct
{
	t_stack	stack;
	t_stack	other_stack;
	int		v[5];				// values
	int		x_i[2]; 			// extreme_indicess
	int		extr_and_elem[2]; 	// always 2 (extremes) & 5 (elements)
	int		pushed;
	int		rotated;
	int		total_stack_size;
	int		is_sub_stack;
	int		top_index_is_ex;
	int		top2_index_is_ex;
	int		mid_index_is_ex;
	int		bot2_index_is_ex;
	int		bot_index_is_ex;
}	t_5s_meta;

int	push_fives_extremes(t_ctr *tcon, t_5s_meta *m);

#endif