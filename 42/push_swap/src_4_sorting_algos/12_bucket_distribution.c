// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   12_bucket_distribution.c                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/05/15 23:51:41 by kasherif          #+#    #+#             */
// /*   Updated: 2025/06/13 00:24:32 by kasherif         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../header_files/push_swap.h"
// #include "../header_files/bucket_sort.h"

// void		handle_bucket_distribution(t_ctr *tcon, t_stack_status *stats,
// 				int bucket);
// static void	move_to_origin_bottom(t_ctr *tcon, t_stack_status *s,
// 				int *moved_bucket);
// static void	move_to_aux_bottom(t_ctr *tcon, t_stack_status *s,
// 				int *moved_bucket);
// static void	move_to_aux_top(t_ctr *tcon, t_stack_status *s,
// 				int *moved_bucket);

// /*
// Clarifications:
// m->parked_3s stores how many bucket-three elements are temporarily parked at a
// 	specific location.
// The while-loops only check whether some 3s are already present at some location.	
// 	The parked_three[X] values can never be negative. Hence, the second "check"
// 	(m->parked_3s[TWO_BUCKET]++ > -1)) is not really a check at all, 
// 	it is there solely to be incremented; to save space in the function.
// the m->bucket_zero, m->bucket_one, etc are all initialized at -(x), where x is 
// 	the	missing amount of elements. So if m->bucket_two ==0, then this bucket is
// 	complete. If that bucket instead is still missing 6 elements, it would be -6
// */
// void	handle_bucket_distribution(t_ctr *tcon, t_stack_status *s, int bucket)
// {
// 	if (bucket == ZERO_BUCKET)
// 	{
// 		while (s->parked_3s[ZERO_BUCKET] > 0 && (s->parked_3s[2]++ > -1))
// 			s->parked_3s[ZERO_BUCKET] -= moving(tcon, s->other_stack, RRR);
// 		move_to_aux_bottom(tcon, s, &(s->bucket_zero));
// 	}
// 	if (bucket == ONE_BUCKET)
// 		move_to_origin_bottom(tcon, s, &(s->bucket_one));
// 	if (bucket == TWO_BUCKET)
// 	{
// 		while (s->parked_3s[TWO_BUCKET] > 1 && (s->parked_3s[0]++ > -1))
// 			s->parked_3s[TWO_BUCKET] -= moving(tcon, s->other_stack, RR);
// 		move_to_aux_top(tcon, s, &(s->bucket_two));
// 		if (s->parked_3s[TWO_BUCKET] == 1)
// 			moving(tcon, s->other_stack, SS);
// 	}
// 	if (bucket == THREE_BUCKET)
// 	{
// 		if (s->bucket_one == 0 && (s->parked_3s[ONE_BUCKET]++ > -1))
// 			move_to_origin_bottom(tcon, s, &(s->bucket_three));
// 		else if ((s->bucket_two == 0 || s->bucket_zero != 0)
// 			&& (s->parked_3s[TWO_BUCKET]++ > -1))
// 			move_to_aux_top(tcon, s, &(s->bucket_three));
// 		else if (s->bucket_zero == 0 && (s->parked_3s[ZERO_BUCKET]++ > -1))
// 			move_to_aux_bottom(tcon, s, &(s->bucket_three));
// 	}
// }

// static void	move_to_origin_bottom(t_ctr *tcon, t_stack_status *s, int *moved_bucket)
// {
// 	*moved_bucket += moving(tcon, s->stack, RR);
// 	s->rotated++;
// 	s->origin_rred++;
// }

// static void	move_to_aux_bottom(t_ctr *tcon, t_stack_status *s, int *moved_bucket)
// {
// 	*moved_bucket += moving(tcon, s->stack, ANY_PUSH);
// 	s->pushed++;
// 	s->aux_rred += moving(tcon, s->other_stack, RR);
// 	s->rotated++;
// }

// static void	move_to_aux_top(t_ctr *tcon, t_stack_status *s, int *moved_bucket)
// {
// 	*moved_bucket += moving(tcon, s->stack, ANY_PUSH);
// 	s->pushed++;
// }
