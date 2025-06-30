/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_limits.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:31:20 by kasherif          #+#    #+#             */
/*   Updated: 2025/04/25 17:31:20 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIZE_LIMITS_H
# define SIZE_LIMITS_H

# define INVALID -1
# define VALID 0

# define SORTED 2	// was voorheen 0. Conseqs?
# define SORTED_REV 3 // was voorheen 2. conseqs?
# define UNSORTED -2

# define NOT_POPULATED -2

# define NO_ACTION_PERFORMED -2 // kan deze worden vervangen

# include "push_swap.h"

enum	size_limits
{
	MAX_S_CHAR = (signed char)((1U << (sizeof(signed char) - 1)) - 1),
	MIN_S_CHAR = -1 - MAX_S_CHAR,
	MAX_SHORT = (short)((1U << (sizeof(short) * 8 - 1)) - 1),
	MIN_SHORT = -1 - MAX_SHORT,
	MAX_INT = (int)((1U << (sizeof(int) * 8 - 1)) - 1),
	MIN_INT = -1 - MAX_INT,
	MAX_LONG = (long)((1UL << (sizeof(long) * 8 - 1)) - 1),
	MIN_LONG = -1 - MAX_LONG,
	MAX_LONG_LONG = (long long)((1ULL << (sizeof(long long) * 8 - 1)) - 1),
	MIN_LONG_LONG = -1 - MAX_LONG_LONG
};

typedef enum e_lives_in_which_stack
{
	STACK_A,
	STACK_B,
	BOTH_STACKS,
	UPPERBOUND,
	LOWERBOUND,
	// STACK_A = 18,
	// STACK_B = 19,
	ASCENDING = 20,
	DESCENDING = 21
	// HIGHEST,
	// LOWEST
}	t_stack;

// typedef enum e_extreme_value_getter
// {
// 	CHUNK_TOP,
// 	CHUNK_BOTTOM
// }	t_extr;

#endif