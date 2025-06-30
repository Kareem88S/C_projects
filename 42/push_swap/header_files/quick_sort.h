/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:53:05 by kasherif          #+#    #+#             */
/*   Updated: 2025/06/07 13:14:52 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SORT_H
# define QUICK_SORT_H

# include "push_swap.h"

typedef struct	s_quick_sort_meta
{
	t_ctr *const	*tcon_p;
	t_n *const		*top_or;
	t_n *const		*top_aux;
	t_n *const		*a_top;
	t_n *const		*b_top;
	t_stack			or_stack;
	t_stack			aux_stack;
	int				sub_size;
	int				origin_is_populated;
	int				aux_is_populated;
	int				max_value;
	int				min_value;
	int				pivot_point;
	int				pushed;
	int				rotated;

}	t_quick;

#endif