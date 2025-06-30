// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   10_bucket_sort.c                                   :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/05/15 23:51:41 by kasherif          #+#    #+#             */
// /*   Updated: 2025/06/22 20:44:39 by kasherif         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../header_files/push_swap.h"
// #include "../header_files/bucket_sort.h"


// int			bucket_sort(t_ctr *tcon, t_stack_status *stats);
// static void	set_bucket_data(t_stack_status *stats, int algo);
// static void	bucket_distribution(t_ctr *tcon, t_stack_status *stats);
// static void	sort_and_return_four(t_ctr *tcon, t_stack_status *stats);
// static void	sort_and_return_three(t_ctr *tcon, t_stack_status *stats);
// // static void	build_bucket_array(t_stack_status *stats, int algo);
// static void	build_bucket_array(t_stack_status *stats, int algo, int *arr);

// /*
// The function works by dividing the working stack into 3 or 4 quadrants; where 
// 	the	most-important bucket is bucket 3. These are the smallest elements in
// 	STACK_A, or the largest elements in STACK_B. Bucket 3 is the foundation.
// Function creates a temporary 'meta-data' struct m. This struct holds heuristic
// 	data on which algo-selection decisions will be based.
// */



// int	bucket_sort(t_ctr *tcon, t_stack_status *stats)
// {
// 	int	bucket_algorithm_selection;

// 	stats->bucket_arr = malloc(sizeof(int) * stats->stack_size);
// 	if (stats->bucket_arr == NULL)
// 		return (INVALID);
// 	bucket_algorithm_selection = B_ALTERNATIVE;
// 	if (stats->stack_size % 4 == 0)					// cheapest??
// 		bucket_algorithm_selection = B_FOUR_SELECTION;
// 	if (stats->stack_size % 3 == 0)					// cheaper?
// 		bucket_algorithm_selection = B_THREE_SELECTION;
// 	set_bucket_data(stats, bucket_algorithm_selection);
// 	bucket_distribution(tcon, stats);
// 	if ((bucket_algorithm_selection == B_THREE_SELECTION) 
// 		|| (bucket_algorithm_selection == B_ALTERNATIVE))
// 		sort_and_return_three(tcon, stats);
// 	if (bucket_algorithm_selection == B_FOUR_SELECTION) 
// 		sort_and_return_four(tcon, stats);
// 	free_and_null((void **) &(stats->bucket_arr));
// 	return (SORTED);
// }

// static void	build_bucket_array(t_stack_status *stats, int algo, int *arr)
// {
// 	int const		b_size = stats->bucket_size;
// 	int				i;

// 	i = -1;
// 	while (++i < stats->stack_size)
// 	{
// 		if (arr[i] < b_size)
// 			stats->bucket_arr[i] = ZERO_BUCKET;
// 		else if (arr[i] < b_size * 2)
// 			stats->bucket_arr[i] = ONE_BUCKET;
// 		else if (algo == B_ALTERNATIVE)
// 			stats->bucket_arr[i] = TWO_BUCKET;
// 		else if (algo == B_THREE_SELECTION)
// 			stats->bucket_arr[i] = TWO_BUCKET;
// 		else if (algo == B_FOUR_SELECTION && arr[i] < b_size * 3)
// 			stats->bucket_arr[i] = TWO_BUCKET;
// 		else if (algo == B_FOUR_SELECTION)
// 			stats->bucket_arr[i] = THREE_BUCKET;
// 	}
// }

// static void	set_bucket_data(t_stack_status *stats, int algo)
// {
// 	int	i;

// 	stats->bucket_size = stats->stack_size / algo;
// 	if (algo == B_ALTERNATIVE)
// 		stats->bucket_size = stats->stack_size / 3;
// 	stats->bucket_zero -= stats->bucket_size;
// 	stats->bucket_one -= stats->bucket_size;
// 	stats->bucket_two -= stats->bucket_size;
// 	if (algo == B_ALTERNATIVE || algo == B_THREE_SELECTION)
// 	{
// 		stats->bucket_two = -(stats->stack_size - (stats->bucket_size * 2));
// 		stats->bucket_two_total = stats->bucket_two;
// 	}
// 	if (algo == B_FOUR_SELECTION)
// 		stats->bucket_three -= stats->bucket_size;
// 	if (stats->stack == STACK_A)
// 		build_bucket_array(stats, algo, stats->norm_arr);
// 	if (stats->stack == STACK_B)
// 		build_bucket_array(stats, algo, stats->norm_rev);
// 	i = -1;
// 	while (++i < stats->bucket_size)
// 		if (((algo == 4) && (stats->bucket_arr[stats->stack_size - 1 - i] == 3))
// 			|| ((algo != 4) && (stats->bucket_arr[stats	->stack_size - 1 - i] == 2)))
// 			if (stats->bot_starters == i)
// 				stats->bot_starters++;
// 	if (algo == 4)
// 		stats->bucket_three += stats->bot_starters;
// 	else
// 		stats->bucket_two += stats->bot_starters;
// 	// i = -1;
// 	// while (++i < 3)
// 	// 	stats->parked_3s[i] = 0;
// }

// static void	bucket_distribution(t_ctr *tcon, t_stack_status *s)
// { 
// 	int	i;
	
// 	i = -1;
// 	while (++i < (s->stack_size - s->bot_starters))
// 	{
// 		if (s->bucket_arr[i] == ZERO_BUCKET)
// 			handle_bucket_distribution(tcon, s, ZERO_BUCKET);
// 		else if (s->bucket_arr[i] == ONE_BUCKET)
// 			handle_bucket_distribution(tcon, s, ONE_BUCKET);
// 		else if (s->bucket_arr[i] == TWO_BUCKET)
// 			handle_bucket_distribution(tcon, s, TWO_BUCKET);
// 		else if (s->bucket_arr[i] == THREE_BUCKET)
// 			handle_bucket_distribution(tcon, s, THREE_BUCKET);
// 	}
// 	while (s->parked_3s[0] || s->parked_3s[1] || s->parked_3s[2])
// 	{
// 		if (s->parked_3s[ZERO_BUCKET] && ++s->parked_3s[TWO_BUCKET])
// 			s->parked_3s[ZERO_BUCKET] -= moving(tcon, s->other_stack, RRR);
// 		if (s->parked_3s[ONE_BUCKET])
// 			s->parked_3s[ONE_BUCKET] -= moving(tcon, s->stack, RRR);
// 		if (s->parked_3s[TWO_BUCKET])
// 			s->parked_3s[TWO_BUCKET] -= moving(tcon, s->other_stack, ANY_PUSH);
// 	}
// }

// /*
// Now that the buckets have been distributed to their locations:
// 	Bucket-0 --> bottom of auxiliary stack
// 	Bucket-1 --> bottom of origin stack
// 	Bucket-2 --> top of auxiliary stack
// 	Bucket-3 --> top of origin stack
// It is finally time to sort each quadrant (by recursively calling the manager)
// 	and then refusing the quadrants back in the stack of origin.

// */
// /*
// Function sorts the prepared quadrants, and returns them to the point of origin.
// The elements currently gathered at the top(s) are sorted: 
// 	If the 4th bucket exists, then the top of the aux stack is sorted as well. 
// 	Then (for bucket-four) the sorted auxiliary stack top is returned to origin.
//   Otherwise (fall-back and 3-b-sorter), the aux-bucket-two elements are pushed
// 	back onto the top of origin, and then that top only is sorted.
// Then the bottoms of both stacks are returned back up, if applicable:
// 	Stack one is RRR'ed to the top of the origin stack, where it rests on top 
// 		of stack two. Here stack one can safely be sorted and rest, awaiting the
// 		arrival of bucket zero. 
// 	If the bucket-zero elements were isolated in the stack,	no further actions
// 	are required to return them to origin, except PUSH.
// 	If, however, bucket-zero elements were buried under "external" elmentents
// 	(elements not part of the sub-stack), then the bucket-zero elements will be
// 	RRR'ed together with the bucket-one elements.
// Finally, the elements of buckets one and two (now at the top of the stacks) are
// 	sorted, and bucket-zero elements PUSH'ed back onto the top of origin.
// */
// static void	sort_and_return_four(t_ctr *tcon, t_stack_status *s)
// {
// 	int	i;
	
// 	sorting_manager(tcon, s->or, s->bucket_size, s->remainables);
// 	sorting_manager(tcon, s->aux, s->bucket_size, s->remainables);
// 	while (s->pushed-- && s->bucket_two < s->bucket_size)		// hier waarschijnlijk niet, maar misscjien ook stelen?
// 		s->bucket_two += moving(tcon, s->other_stack, ANY_PUSH);
// 	i = -1;
// 	while (++i < s->bucket_size)
// 	{
// 		if (s->aux_is_sub_stack && s->aux_rred && (s->aux_rred-- > 0))
// 			s->origin_rred -= moving(tcon, BOTH_STACKS, RRR);
// 		else
// 			s->origin_rred -= moving(tcon, s->stack, RRR);
// 	}
// 	while (s->aux_is_sub_stack && s->aux_rred && (s->aux_rred-- > 0))
// 		moving(tcon, s->other_stack, RRR);
// 	sorting_manager(tcon, s->or, s->bucket_size, s->remainables);
// 	sorting_manager(tcon, s->aux, s->bucket_size, s->remainables);
// 	// while (s->pushed > 0 && s->pushed-- > -1)
// 	// 	s->bucket_zero -= moving(tcon, s->other_stack, ANY_PUSH);
// 	i = -1;
// 	while (++i < s->bucket_size)
// 		s->bucket_zero -= moving(tcon, s->other_stack, ANY_PUSH);
// }

// static void	sort_and_return_three(t_ctr *tcon, t_stack_status *s)//, int algo)
// {
// 	int			i;

// 	// while (m->bucket_two_total <= (m->bucket_two - m->bot_starters))
// 	while (s->bucket_size < s->pushed)
// 	{
// 		// eerst een SS eventueel -- NA DE DEBUG
// 		s->pushed--;
// 		s->bucket_two -= moving(tcon, s->other_stack, ANY_PUSH);
// 	}
// 	s->bucket_two_total *= -1;
// 	sorting_manager(tcon, s->or, s->bucket_two_total, s->remainables);
// 	// while (m->bucket_two < m->bucket_size && m->pushed-- > -1)
// 		// m->bucket_two += moving(tcon, m->other_stack, ANY_PUSH);
// 	i = -1;
// 	while (++i < s->bucket_size)
// 	{
// 		if (s->aux_is_sub_stack && (s->aux_rred-- > 0))
// 			(*(s->aux))->rotate_rev = WAITING_FOR_RRR;
// 		s->origin_rred -= moving(tcon, s->stack, RRR);
// 	}
// 	while (s->aux_is_sub_stack && (s->aux_rred-- > 0))
// 		moving(tcon, s->other_stack, RRR);
// 	sorting_manager(tcon, s->or, s->bucket_size, s->remainables);
// 	sorting_manager(tcon, s->aux, s->bucket_size, s->remainables);
// 	while (s->pushed > 0 && s->pushed-- > -1)
// 		s->bucket_zero -= moving(tcon, s->other_stack, ANY_PUSH);
// }
