/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_reverse_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 03:36:38 by kasherif          #+#    #+#             */
/*   Updated: 2025/04/05 03:36:38 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

#define NOT 0
#define FIVE 5
#define JUST_PUSHED 2
#define LAST_ELEMENT 1
// 		****	Flags:		****
#define AUX_EMPTY 1
#define ORIG_EMPTY 2
#define AUX_SMALLER 4
#define ORIG_SMALLER 8
#define ONLY_LARGE_STACKS 8
#define ORIGIN_IS_STACK_A 16

int			reverse_sort(t_ctr *tcon, t_stack_status *s);
// static void	count_outliers(t_stack_status *s, unsigned char flags);
static void	seperate_outliers(t_ctr *tcon, t_stack_status *s, unsigned char flags);
// static void	sort_and_place_outliers(t_ctr *tcon, t_stack_status *s, unsigned char fls);
// static void	fuse_elements(t_ctr *tcon, t_stack_status *s, unsigned char flags);

/*
1) Cheapest is empty stack: only reverse + push (no need to forward-rotate);
2) few out-of-scope elements: can rotate out-of-the-way;
3) most expensive when both stacks are packed with out-of-scope elements. This
	requires elements to first rotate forward, then return + push 1 at a time.
Passing on ** to the top of both stacks.
First checks the status and setting the bit-flag accordingly (see macros above):
	* Check which stack (A or B)
	* Checks for empty host-stack (no reversible actions required)
	* checks for smaller host-stack than sub-stack (few RRs required)
		if neither empty nor small: count RR and match RRRs (more expensive)
*/
int	reverse_sort(t_ctr *tcon, t_stack_status *s)
{
	int const		size = s->stack_size;
	unsigned char	selection_flags;

	// s->outliers = 0;
	selection_flags = 0;
	if (s->stack == STACK_A)
		selection_flags |= ORIGIN_IS_STACK_A;
	if (s->or_is_sub_stack == 0)
		selection_flags |= ORIG_EMPTY;
	else if (s->aux_is_sub_stack == 0)
		selection_flags |= AUX_EMPTY;
	else if ((s->or_is_sub_stack < size) || (s->aux_is_sub_stack < size))
	{
		if (s->or_is_sub_stack <= s->aux_is_sub_stack)
			selection_flags |= ORIG_SMALLER;
		else if (s->aux_is_sub_stack < s->or_is_sub_stack)
			selection_flags |= AUX_SMALLER;
	}
	// count_outliers(s, selection_flags);
	seperate_outliers(tcon, s, selection_flags);
	// sort_outliers_and_place_all_elements(tcon, s, selection_flags);
	// fuse_elements(tcon, s, selection_flags);
	return (SORTED);
}

/*
Pre-counts how many elements are off their index by more then 2.
*/
// static void	count_outliers(t_stack_status *s, unsigned char flags)
// {
// 	int	i;
// 	t_n	*temp;

// 	i = -1;
// 	s->outliers = 0;
// 	if (flags & ORIGIN_IS_STACK_A)
// 		temp = (*s->s_a);
// 	if ((flags & ORIGIN_IS_STACK_A) == NOT)
// 		temp = (*s->s_b);
// 	while (flags & ORIGIN_IS_STACK_A && ++i < s->stack_size)
// 	{
// 		if (abs(temp->n_stats.off_by_rev) > 2)
// 			s->outliers++;
// 		temp = temp->previous;
// 	}
// }

/*
If stack A, the in-range elements are pushed to B, the outliers remain 
	in A: they are RR'ed to the bottom of stack A. 
	The full sub-stack is traversed, so all in-range are in B,
	all outliers are at the bottom of A.

If stack B, the in-range elements are RR'd to the bottom of stack B. The outliers
	are pushed to stack A. 
	The function ends prematurely if all outliers have been pushed out, awaiting
	simultanious movements.
*/
static void	seperate_outliers(t_ctr *tcon, t_stack_status *s, unsigned char flags)
{
	int	i;

	i = -1;
	while ((flags & ORIGIN_IS_STACK_A) && ++i < s->stack_size)
	{
		if ((abs((*s->or)->n_stats.off_by_rev) > 2))
		// {
		// 	if (s->pushed > s->aux_rred && ++s->aux_rred)
		// 		s->rotated += moving(tcon, BOTH_STACKS, RR);
		// 	else
				s->rotated += moving(tcon, STACK_A, RR);
		// }
		else
			s->pushed += moving(tcon, STACK_A, ANY_PUSH);
	}
	while (((flags & ORIGIN_IS_STACK_A) == NOT) && ++i < s->stack_size
		&& i < s->outliers)
	{
		if ((abs((*s->or)->n_stats.off_by_rev) > 2))
			s->pushed += moving(tcon, STACK_A, ANY_PUSH);
		else
			s->rotated += moving(tcon, STACK_B, RR);
	}
}




// /*
// Outliers must first be sorted before checked against the main stack.
// If stack A, the outliers were pushed down:
// 	If these are the only elements left in the stack, only sorting will suffice;
// 	If unrelated elements in the way, the stack needs to be RRA'd back up first;
// 	Then sorted;

// 	Finally moved back out of the way again -- if other elements.


// If stack B, the outliers are pushed to stack A. In this case, they can never
// 	be the only elements: it means that the sub-stack was first pushed to B 
// 	(eg. by quick-sort), so stack A will always be populated, which means the 
// 	elements are lingering at the top, ready to be sorted.


// 	They then require RA's to be moved out of the way. Simultaniously, in-line
// 	elements may be RB'ed downwards, IF there are other elements to consider.
// */
// // NB: s->or_is_sub_stack == "total origin stack size - (s->stack_size == sub stack size)
// // static void	get_outliers_on_top(t_ctr *tcon, t_stack_status *s, unsigned char fls)
// // {
// // 	int	i;

// // 	i = -1;
// // 	if ((fls & ORIGIN_IS_STACK_A) == NOT) // meaning it is stack B..
// // 		return ;	// because if origin is stack B, the ourliers are only pushed to A, so already on top
// // 	// so this function only operates if the origin stack is stack A
// // 	if ((fls & ORIGIN_IS_STACK_A) && (s->or_is_sub_stack == NOT)) // meaning no out-of-scope elements
// // 		return ;	// meaning the outliers are already on top
	
// // 	if (s->or_is_sub_stack < s->outliers)	// cheaper to out-of-scopes out of the way. not the case if 499 - 100 are already in place
// // 	{
// // 		while (++i < s->or_is_sub_stack)
// // 		{
// // 			// since in-range elements were only pushed, they need to end up at the bottom - FIVE.
// // 			// here if depends if stack B is populated with out-of-scopes, or otherwise empty)

// // 			moving(tcon, s->stack, RR);
// // 		}
// // 	}
// // 	else
// // 	{
// // 		// here it also depends on the state of B what to do simultaniously
// // 		while (++i < s->outliers)
// // 			s->rotated -= moving(tcon, s->stack, RRR);
// // 	}
// // }
// static void	get_outliers_on_top(t_ctr *tcon, t_stack_status *s, unsigned char fls)
// {
// 	int	i;

// 	i = -1;
// 	if ((fls & ORIGIN_IS_STACK_A) == NOT)
// 		return ;
// 	if ((fls & ORIGIN_IS_STACK_A) && (s->or_is_sub_stack == NOT))
// 		return ;
	
// 	if (s->or_is_sub_stack < s->outliers)
// 	{
// 		while (++i < s->or_is_sub_stack)
// 		{
// 			if (!(fls & AUX_EMPTY) && s->aux_rred < s->pushed && ++s->aux_rred)
// 				smoving(tcon, BOTH_STACKS, RR);
// 				// s->rotated += moving(tcon, BOTH_STACKS, RR);
// 			else
// 				moving(tcon, STACK_A, RR);
// 				// s->rotated += moving(tcon, STACK_A, RR);
// 		}
// 	}
// 	else
// 	{
// 		while (++i < s->outliers)
// 		{
// 			if (((fls & AUX_EMPTY) == NOT) && (s->aux_rred > 0) && ++s->aux_rred)
// 				s->rotated -= moving(tcon, BOTH_STACKS, RRR);
// 			else
// 				s->rotated -= moving(tcon, STACK_A, RRR);		
// 		}
// 	}
// }


// static void	get_outliers_on_top(t_ctr *tcon, t_stack_status *s, unsigned char fls)
// {
// 	int	i;

// 	i = -1;
// 	if ((fls & ORIGIN_IS_STACK_A) == NOT)
// 		return ;
// 	if ((fls & ORIGIN_IS_STACK_A) && (s->or_is_sub_stack == NOT))
// 		return ;

// 	if (s->or_is_sub_stack < s->outliers)
// 	{
// 		// Rotate non-outliers away (to bottom of A), to expose outliers at top
// 		while (++i < s->or_is_sub_stack)
// 		{
// 			if ((fls & AUX_EMPTY) == NOT && s->aux_rred < s->pushed)
// 			{
// 				s->aux_rred++;
// 				s->rotated += moving(tcon, BOTH_STACKS, RR);
// 			}
// 			else
// 			{
// 				s->rotated += moving(tcon, STACK_A, RR);
// 			}
// 		}
// 	}
// 	else
// 	{
// 		// Bring outliers from bottom back to top of A
// 		while (++i < s->outliers)
// 		{
// 			if ((fls & AUX_EMPTY) == NOT && s->aux_rred > 0)
// 			{
// 				s->aux_rred--;
// 				s->rotated -= moving(tcon, BOTH_STACKS, RRR);
// 			}
// 			else
// 			{
// 				s->rotated -= moving(tcon, STACK_A, RRR);
// 			}
// 		}
// 	}
// }




// static void	sort_outliers_and_place_all_elements(t_ctr *tcon, t_stack_status *s, unsigned char fls)
// {
// 	// int	i;	
// 	// i = -1;
// 	if ((fls & ORIGIN_IS_STACK_A) && s->or_is_sub_stack)
// 		get_outliers_on_top(tcon, s, fls);
// 	sorting_manager(tcon, s->s_a, s->outliers, NULL);
// // place
// 	get_outliers_down();
// 	i = -1;
// 	if ((fls & ORIGIN_IS_STACK_A) && s->or_is_sub_stack)
// 	{
// 		if (s->or_is_sub_stack < s->outliers)
// 			while (++i < s->or_is_sub_stack)
// 				moving(tcon, s->stack, RRR);
// 		else
// 			while (++i < s->outliers)
// 				s->rotated += moving(tcon, s->stack, RR);
// 	}
// 	while ((fls & ORIGIN_IS_STACK_A) && s->or_is_sub_stack && ++i < s->outliers)
// 		s->rotated += moving(tcon, s->stack, RR);


// 	if (!(fls & ORIGIN_IS_STACK_A))
// 	{
// 		if (s->or_is_sub_stack == 0)
// 		{
// 			while (++i < s->outliers)
// 				s->aux_rred += moving(tcon, STACK_A, RR);
// 			i = -1;
// 			while (++i < FIVE)
// 				s->rotated -= moving(tcon, s->stack, RRR);
// 		}
// 		else if (s->or_is_sub_stack + FIVE < s->pushed)
// 		{
// 			while (++i < s->outliers)
// 				s->aux_rred += moving(tcon, STACK_A, RR);
// 			i = -1;
// 			while (++i < s->or_is_sub_stack + FIVE)
// 				s->rotated -= moving(tcon, s->stack, RRR);
// 		}
// 		else
// 		{
// 			while (++i < s->pushed - FIVE)
// 			{
// 				if (i < s->outliers)
// 					s->aux_rred += moving(tcon, BOTH_STACKS, RR);
// 				else
// 					s->rotated += moving(tcon, s->stack, RR);
// 			}
// 		}
// 	}
// }





// /*
// Starts by sorting the top 5 in-line elements on stack B, which always in the
// 	two lowest elements in stack A (JUST_PUSHED).
// Then enters the loop, with the counter set to 2.
// */
// static void	fuse_elements(t_ctr *tcon, t_stack_status *s, unsigned char flags)
// {
// 	int	i;
// 	int	counter;
	
// 	sorting_manager(tcon, s->s_b, FIVE, NULL);
// 	counter = JUST_PUSHED;
// 	i = -1;
// 	while (++i < s->stack_size - JUST_PUSHED)
// 	{
// 		if (i % 3 == 0)
// 			sorting_manager(tcon, s->s_a, FIVE, NULL);
// 		if (!s->outliers && ++counter)
// 			s->pushed -= moving(tcon, STACK_B, ANY_PUSH);
// 		else if (!s->pushed)
// 			s->rotated -= moving(tcon, STACK_A, RRR);
// 		else if (!s->rotated)
// 			s->pushed -= moving(tcon, s->other_stack, ANY_PUSH);
// 		else if (tcon->a_bottom->normalized_value
// 			< tcon->b_top->normalized_value)
// 			s->pushed -= moving(tcon, s->other_stack, ANY_PUSH);
// 		else
// 			s->rotated -= moving(tcon, s->stack, RRR);
// 		if (counter == 5)
// 		{
// 			while ((flags & ORIGIN_IS_STACK_A) && counter-- > 0)
// 				s->aux_rred -= moving(tcon, STACK_B, RRR);
// 			while (!(flags & ORIGIN_IS_STACK_A) && counter-- > 0)
// 				s->rotated -= moving(tcon, STACK_B, RRR);
// 			counter = 0;
// 		}
// 	}
// }

// // static int	reverse_expensive(t_ctr *tcon, t_stack_status *s, unsigned char flags)
// // {

// // 	// the extremes stay in A. perfect. Firrst check for larger outliers
// // 	sorting_manager(tcon, s->aux, FIVE, NULL);
// // 	counter = s->rotated;
// // 	// i = 0;
// // 	// while (outliers && (*s->or)->next->normalized_value >= (s->max_value - 3))
// // 	// {
// // 	// 	if (i++ < JUST_PUSHED)
// // 	// 	{
// // 	// 		s->rotated -= moving(tcon, BOTH_STACKS, RRR);
// // 	// 		s->aux_rred--;
// // 	// 	}
// // 	// 	else
// // 	// 		s->rotated -= moving(tcon, s->stack, RRR);//	<-- might be cheaper but unpredicatble	
// // 	// }
// // 	// if (counter - s->rotated)
// // 	// 	sorting_manager(tcon, s->or, JUST_PUSHED + counter - s->rotated, NULL);

// // 	while (outliers && (*s->or)->next->normalized_value >= (s->max_value - JUST_PUSHED))
// // 	{
// // 		s->rotated -= moving(tcon, BOTH_STACKS, RRR);
// // 		s->aux_rred--;
// // 	}
// // 	if (counter - s->rotated)
// // 		sorting_manager(tcon, s->or, JUST_PUSHED + counter - s->rotated, NULL);

// // 	i = -1;
// // 	counter = s->pushed;		// we should here assume 2 are pushed to A already
// // 	while ((s->rotated && (s->pushed + s->rotated) > 0) && (++i > -1))
// // 	{
// // 		if ((i % 3 == 0) && i >= 3) // already 2 elements present + 3 == 5
// // 		// if ((i % 3 == 0) && (s->stack_size - (s->pushed + s->rotated)) >= FIVE)
// // 			sorting_manager(tcon, s->or, FIVE, NULL);

// // 		if (!s->pushed)
// // 			s->rotated -= moving(tcon, s->stack, RRR);	

// // 		else if (!s->rotated)
// // 		{
// // 			if (i > 2)
// // 				s->aux_rred -= moving(tcon, s->other_stack, RRR);
// // 			s->pushed -= moving(tcon, s->other_stack, ANY_PUSH);
// // 			// counter++;
// // 		}

// // 		else if ((*s->or)->next->normalized_value
// // 			< (*s->aux)->normalized_value)
// // 			s->pushed -= moving(tcon, s->other_stack, ANY_PUSH);
// // 		else
// // 			s->rotated -= moving(tcon, s->stack, RRR);
// // 		if (counter - s->pushed >= 2)	// ideally BOTH_STACKS
// // 		{
// // 			s->aux_rred -= moving(tcon, s->other_stack, RRR);
// // 			counter = s->pushed;
// // 		}
// // 	}

// // 	// if all outliers have been merged and only reversed elements remain
// // 	while (s->pushed)
// // 	{

// // 	}

// // 	return (SORTED);
// // }
// 				// static int	reverse_expensive(t_ctr *tcon, t_stack_status *s, unsigned char flags)
// 				// {
// 				// 	int	i;
// 				// 	int	counter;
// 				// 	int	outliers;

// 				// 	/*
// 				// 	if STACK A --> first push
// 				// 		when outlier, rotate both stacks
// 				// 		eventually rotate all.
// 				// 	to return: if outlier >
// 				// 		RRR both stacks
// 				// 		if again outlier
// 				// 			RRR only until max 5 
// 				// 				in that case, call 


// 				// 	*/
// 				// 	outliers = 0;
// 				// 	i = -1;
// 				// 	// while ((flags &= ORIGIN_IS_STACK_A) && (++i < s->stack_size - LAST_ELEMENT))
// 				// 	while ((flags & ORIGIN_IS_STACK_A) && (++i < s->stack_size))
// 				// 	{
// 				// 		if ((abs((*s->or)->n_stats.off_by_rev) > 2) && ++outliers)
// 				// 			s->rotated += moving(tcon, s->stack, RR);
// 				// 		else
// 				// 			s->pushed += moving(tcon, s->stack, ANY_PUSH);
// 				// 	}
// 				// 	i = -1;
// 				// 	// return and sort outliers
// 				// 	while (outliers && ++i < outliers)
// 				// 		s->rotated -= moving(tcon, s->stack, RRR);
// 				// 	if (outliers)
// 				// 		sorting_manager(tcon, s->or, outliers, NULL);

// 				// 	// move away outliers again
// 				// 	while (outliers > s->rotated && (++s->aux_rred))
// 				// 		s->rotated += moving(tcon, BOTH_STACKS, RR);
// 				// 	// move away stack B's normal reversed - FIVE to be sorted
// 				// 	i = -1;
// 				// 	while (s->aux_rred < (s->pushed - FIVE))		// if empty stack: RRR x5
// 				// 		s->aux_rred += moving(tcon, s->other_stack, RR);
// 				// 	// the extremes stay in A. perfect. Firrst check for larger outliers
// 				// 	sorting_manager(tcon, s->aux, FIVE, NULL);
// 				// 	counter = s->rotated;
// 				// 	// i = 0;
// 				// 	// while (outliers && (*s->or)->next->normalized_value >= (s->max_value - 3))
// 				// 	// {
// 				// 	// 	if (i++ < JUST_PUSHED)
// 				// 	// 	{
// 				// 	// 		s->rotated -= moving(tcon, BOTH_STACKS, RRR);
// 				// 	// 		s->aux_rred--;
// 				// 	// 	}
// 				// 	// 	else
// 				// 	// 		s->rotated -= moving(tcon, s->stack, RRR);//	<-- might be cheaper but unpredicatble	
// 				// 	// }
// 				// 	// if (counter - s->rotated)
// 				// 	// 	sorting_manager(tcon, s->or, JUST_PUSHED + counter - s->rotated, NULL);

// 				// 	while (outliers && (*s->or)->next->normalized_value >= (s->max_value - JUST_PUSHED))
// 				// 	{
// 				// 		s->rotated -= moving(tcon, BOTH_STACKS, RRR);
// 				// 		s->aux_rred--;
// 				// 	}
// 				// 	if (counter - s->rotated)
// 				// 		sorting_manager(tcon, s->or, JUST_PUSHED + counter - s->rotated, NULL);

// 				// 	i = -1;
// 				// 	counter = s->pushed;		// we should here assume 2 are pushed to A already
// 				// 	while ((s->rotated && (s->pushed + s->rotated) > 0) && (++i > -1))
// 				// 	{
// 				// 		if ((i % 3 == 0) && i >= 3) // already 2 elements present + 3 == 5
// 				// 		// if ((i % 3 == 0) && (s->stack_size - (s->pushed + s->rotated)) >= FIVE)
// 				// 			sorting_manager(tcon, s->or, FIVE, NULL);

// 				// 		if (!s->pushed)
// 				// 			s->rotated -= moving(tcon, s->stack, RRR);	

// 				// 		else if (!s->rotated)
// 				// 		{
// 				// 			if (i > 2)
// 				// 				s->aux_rred -= moving(tcon, s->other_stack, RRR);
// 				// 			s->pushed -= moving(tcon, s->other_stack, ANY_PUSH);
// 				// 			// counter++;
// 				// 		}

// 				// 		else if ((*s->or)->next->normalized_value
// 				// 			< (*s->aux)->normalized_value)
// 				// 			s->pushed -= moving(tcon, s->other_stack, ANY_PUSH);
// 				// 		else
// 				// 			s->rotated -= moving(tcon, s->stack, RRR);
// 				// 		if (counter - s->pushed >= 2)	// ideally BOTH_STACKS
// 				// 		{
// 				// 			s->aux_rred -= moving(tcon, s->other_stack, RRR);
// 				// 			counter = s->pushed;
// 				// 		}
// 				// 	}

// 				// 	// if all outliers have been merged and only reversed elements remain
// 				// 	while (s->pushed)
// 				// 	{

// 				// 	}

// 				// 	return (SORTED);
// 				// }
// 	// i = -1;
// 	// j = 0;
// 	// while (((stats->pushed + stats->rotated) > 0) && (++i > -1))
// 	// {
// 	// 	if ((i % 3 == 0) && i >= FIVE)
// 	// 		sorting_manager(tcon, stats->or, FIVE, NULL);
// 	// 	if (!stats->pushed)
// 	// 		stats->rotated -= moving(tcon, stats->stack, RRR);		
// 	// 	else if (!stats->rotated)
// 	// 		stats->pushed -= moving(tcon, stats->other_stack, ANY_PUSH);
// 	// 	else if ((*stats->or)->next->normalized_value
// 	// 		< (*stats->aux)->normalized_value)
// 	// 		stats->pushed -= moving(tcon, stats->other_stack, ANY_PUSH);
// 	// 	else
// 	// 		stats->rotated -= moving(tcon, stats->stack, RRR);		
// 	// }


// // 	while (++i < s->stack_size)
// // 	{

// // 	}
// // 	// merge first 3 of stack B to A, RRR 2 more, sort 5, repeat.



// // 	if () // check if last elements is outlier
	
// // 	moving(tcon, s->stack, ANY_PUSH);
// // 	i = 0;
// // 	while (++i < s->stack_size)
// // 	{
// // 		moving(tcon, s->stack, RRR);
// // 		moving(tcon, s->stack, ANY_PUSH);
// // 		if (i >= 5 && (i == s->stack_size - 1 || i % 3 == 0))
// // 			sorting_manager(tcon, s->or, FIVE, NULL); // other stack?
// // 	}
// // 	i = -1;
// // 	while (++i < s->stack_size)
// // 		moving(tcon, s->other_stack, ANY_PUSH);
// // 	return (SORTED);
// // }



// // // buckup
// // // static int	reverse_expensive(t_ctr *tcon, t_stack_status *s)
// // // {
// // // 	int	i;
// // // 	int	outliers;

// // // 	i = -1;
// // // 	while (++i < s->stack_size - LAST_ELEMENT)
// // // 	{

// // // 		moving(tcon, s->stack, RR);
// // // 	}
// // // 	if () // check if last elements is outlier

// // // 	moving(tcon, s->stack, ANY_PUSH);
// // // 	i = 0;
// // // 	while (++i < s->stack_size)
// // // 	{
// // // 		moving(tcon, s->stack, RRR);
// // // 		moving(tcon, s->stack_size, ANY_PUSH);	// error -- not size
// // // 		if (i >= 5 && (i == s->stack_size - 1 || i % 3 == 0))
// // // 			sorting_manager(tcon, s->or, FIVE, NULL);	// error? aux?
// // // 	}
// // // 	i = -1;
// // // 	while (++i < s->stack_size)
// // // 		moving(tcon, s->other_stack, ANY_PUSH);
// // // 	return (SORTED);
// // // }

// // /*
// // Pushes the elements to the other stack.
// // If the other stack (auxiliary) is empty or smaller, simple pushes will do.
// // If this stack is empty, the reversal process starts by reverse rotating + push
// // If this stack has few  elements, the above process applies, but first the
// // 	"out-of-scope" elements are reverse-rotated out of the way (away from the 
// // 	bottom, and onto the top).
// // */
// // // static void	push_on_special(t_ctr *tcon, t_n *const *top_or,
// // // 		int size, unsigned char flags)
// // static void	push_on_special(t_ctr *tcon, t_stack_status *s, unsigned char flags)
// // {
// // 	int const	stack_blockade = s->or_is_sub_stack;
// // 	int			i;

// // 	i = -1;
// // 	while ((flags & (AUX_SMALLER | AUX_EMPTY)) && (++i < s->stack_size))
// // 	{
// // 		moving(tcon, s->stack, ANY_PUSH);
// // 	}
// // 	while ((flags & ORIG_SMALLER) && (++i < stack_blockade))
// // 		moving(tcon, s->stack, RRR);
// // 	i = -1;
// // 	while ((flags & (ORIG_SMALLER | ORIG_EMPTY)) && (++i < s->stack_size))
// // 	{
// // 		if (i < s->stack_size - LAST_ELEMENT)
// // 			moving(tcon, s->stack, RRR);
// // 		moving(tcon, s->stack, ANY_PUSH);
// // 	}
// // }

// // /*
// // If applicable: 
// // first reverse-rotates all "out-of-scope" elements away from the stack's bottom,
// // Always:
// // then pushes elements back to the stack of origin.
// // Sorts elements up to two positions away from target in the process.
// // */
// // // static void	reverse_and_return_on_special(t_ctr *tcon, t_n *const *top_au,
// // // 		int size, unsigned char flags)
// // static void	reverse_and_return_on_special(t_ctr *tcon, t_stack_status *s,
// // 				unsigned char flags)
// // {
// // 	// int const	stack_blockade = s->aux_is_sub_stack; // of deze beter?
// // 	int const	stack_blockade = s->aux_is_sub_stack - s->stack_size;
// // 	// int const		out_of_scope_count = *((*top_au)->this_stack_size) - size;
// // 	int				i;

// // 	// origin = &(tcon->a_top);
// // 	// if ((*top_au)->lives_in_stack == STACK_A)
// // 	// 	origin = &(tcon->b_top);
// // 	i = -1;
// // 	while ((flags & AUX_SMALLER) && (++i < stack_blockade))
// // 		moving(tcon, s->other_stack, RRR);
// // 	i = -1;
// // 	while (++i < s->stack_size)
// // 	{
// // 		if (flags & AUX_EMPTY)
// // 		{
// // 			if (i < s->stack_size - LAST_ELEMENT)
// // 				moving(tcon, s->other_stack, RRR);
// // 			moving(tcon, s->other_stack, ANY_PUSH);
// // 		}
// // 		if (flags & ORIG_EMPTY)
// // 			moving(tcon, s->other_stack, ANY_PUSH);
// // 		if (i > 0 && (i == 5 || i == s->stack_size - 1 || i % 3 == 0))
// // 			sorting_manager(tcon, s->or, FIVE, NULL);
// // 	}
// // }
// // // static void	reverse_and_return_on_special(t_ctr *tcon, t_stack_status *s,
// // // 				unsigned char flags)
// // // {
// // // 	// int const	stack_blockade = s->aux_is_sub_stack - s->stack_size;

// // // 	int const		out_of_scope_count = *((*top_au)->this_stack_size) - size;
// // // 	t_n				**origin;
// // // 	int				i;

// // // 	origin = &(tcon->a_top);
// // // 	if ((*top_au)->lives_in_stack == STACK_A)
// // // 		origin = &(tcon->b_top);
// // // 	i = -1;
// // // 	while ((flags & AUX_SMALLER) && (++i < out_of_scope_count))
// // // 		moving(tcon, (*top_au)->lives_in_stack, RRR);
// // // 	i = -1;
// // // 	while (++i < size)
// // // 	{
// // // 		if (flags & AUX_EMPTY)
// // // 		{
// // // 			if (i < size - LAST_ELEMENT)
// // // 				moving(tcon, (*top_au)->lives_in_stack, RRR);
// // // 			moving(tcon, (*top_au)->lives_in_stack, ANY_PUSH);
// // // 		}
// // // 		if (flags & ORIG_EMPTY)
// // // 			moving(tcon, (*top_au)->lives_in_stack, ANY_PUSH);
// // // 		if (i > 0 && (i == 5 || i == size - 1 || i % 3 == 0))
// // // 			sorting_manager(tcon, origin, FIVE, NULL);
// // // 	}
// // // }
