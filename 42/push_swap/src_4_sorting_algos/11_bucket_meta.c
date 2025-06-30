// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   11_bucket_meta.c                                   :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/05/18 23:28:32 by kasherif          #+#    #+#             */
// /*   Updated: 2025/06/22 21:08:40 by kasherif         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../header_files/push_swap.h"
// #include "../header_files/bucket_sort.h"

// void	set_bucket_contents(t_stack_status *stats, int alg);

// /*
// Function handles arrays in various ways:
// 	- 1) mallocs the usable arrays
// 		frees and returns upon fail
// 	- 2) retrieves the required contents from the LL-nodes for
// 		- a the "actual values" (array m->v);
// 		- b normalizes these values for use in this bucket-sort function;
// 		- c divides the normalized array into 4 buckets.
// 	- 3) the final loop checks how many "Foundation-bucket" elements are already
// 	located at the bottom of the stack: Contigiously starting from bottom-up 
// 	reduces required moves.
// */
// void	set_bucket_contents(t_stack_status *s, int alg)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < s->bucket_size)
// 		if (((alg == 4) && (s->bucket_arr[s->stack_size - 1 - i] == 3))
// 			|| ((alg != 4) && (s->bucket_arr[s->stack_size - 1 - i] == 2)))
// 			if (s->bot_starters == i)
// 				s->bot_starters++;
	
// 	// dit hierboven te vroeg?? haha lol. dubblercheker
	
// 	i = -1;
// 	while (++i < s->stack_size)
// 	{
// 		if (s->norm_arr[i] < s->bucket_size)
// 			s->bucket_arr[i] = ZERO_BUCKET;
// 		else if (s->norm_arr[i] < s->bucket_size * 2)
// 			s->bucket_arr[i] = ONE_BUCKET;
// 		else if (alg == B_ALTERNATIVE)
// 			s->bucket_arr[i] = TWO_BUCKET;
// 		else if (alg == B_THREE_SELECTION)
// 			s->bucket_arr[i] = TWO_BUCKET;
// 		else if (alg == B_FOUR_SELECTION && s->norm_arr[i] < s->bucket_size * 3)
// 			s->bucket_arr[i] = TWO_BUCKET;
// 		else if (alg == B_FOUR_SELECTION)
// 			s->bucket_arr[i] = THREE_BUCKET;
// 	}
// }
// // haha nog geen stack-b geimplementeerd? bucket-rev