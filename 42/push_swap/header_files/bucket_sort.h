/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:02:06 by kasherif          #+#    #+#             */
/*   Updated: 2025/06/13 00:18:50 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUCKET_FOUR_SORT_H
# define BUCKET_FOUR_SORT_H

# include "push_swap.h"

# define ZERO_BUCKET 0
# define ONE_BUCKET 1
# define TWO_BUCKET 2
# define THREE_BUCKET 3
# define B_THREE_SELECTION 3
# define B_FOUR_SELECTION 4
# define B_ALTERNATIVE 100

// Function in 10_bucket_sort.c
int		bucket_sort(t_ctr *tcon, t_stack_status *stats);
// Function in 11_bucket_meta.c
void	set_bucket_contents(t_stack_status *stats, int algo);
// Function in 12_bucket_distribution.c
void	handle_bucket_distribution(t_ctr *tcon, t_stack_status *stats,
				int bucket);

#endif
