/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_operations.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 03:25:16 by kasherif          #+#    #+#             */
/*   Updated: 2025/04/26 03:25:16 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_OPERATIONS_H
# define MOVE_OPERATIONS_H

# include "push_swap.h"

typedef enum e_moves
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	ANY_PUSH,
	NO_MOVE_REQ
}	t_mv;

typedef enum	e_queue
{
	WAITING_FOR_RR,
	WAITING_FOR_RRR,
	WAITING_FOR_SS,
	NONE
}	t_mv_q;

#endif