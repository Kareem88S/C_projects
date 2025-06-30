/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_free_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:09:10 by kasherif          #+#    #+#             */
/*   Updated: 2025/04/25 17:09:10 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

void		error_msg_free_all(t_ctr *tcon);
void		free_all(t_ctr *tcon);
void		free_and_null(void **ptr);
static void	free_t_controller_and_subs(t_ctr *tcon);
static void	free_linked_list(t_n *node);

void	error_msg_free_all(t_ctr *tcon)
{
	write(2, "ERROR\n", 6);
	free_all(tcon);
	return ;
}

void	free_all(t_ctr *tcon)
{
	if (!tcon)
		return ;
	free_t_controller_and_subs(tcon);
	free_and_null((void **) &tcon);
}

void	free_and_null(void **ptr)
{
	if (ptr && *ptr)
	{
		free (*ptr);
		*ptr = NULL;
	}
}

static void	free_t_controller_and_subs(t_ctr *tcon)
{
	if (tcon->nbr_arr)
		free_and_null((void **) &tcon->nbr_arr);
	if (tcon->norm_arr)
		free_and_null((void **) &tcon->norm_arr);
	if (tcon->a_top)
		free_linked_list(tcon->a_top);
	if (tcon->b_top)
		free_linked_list(tcon->b_top);
}

static void	free_linked_list(t_n *node)
{
	t_n	*temp;

	if (node->next == node && node->previous == node)
	{
		node->next = NULL;
		node->previous = NULL;
	}
	else
		node->next->previous = NULL;
	while (node != NULL)
	{
		temp = node->previous;
		node->next = NULL;
		node->previous = NULL;
		free_and_null((void **) &node);
		node = temp;
	}
}
