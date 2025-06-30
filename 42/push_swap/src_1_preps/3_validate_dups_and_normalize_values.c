/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_validate_dups_and_normalize_values.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 01:16:29 by kasherif          #+#    #+#             */
/*   Updated: 2025/04/26 01:16:29 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

int			validate_dups_and_normalize_values(t_ctr *tcon);
static int	check_for_duplicates(t_ctr *tcon);
static int	normalize_data_in_array(t_ctr *tcon);

int	validate_dups_and_normalize_values(t_ctr *tcon)
{
	if (check_for_duplicates(tcon) == INVALID)
		return (error_msg_free_all(tcon), INVALID);
	normalize_data_in_array(tcon);
	return (VALID);
}

static int	check_for_duplicates(t_ctr *tcon)
{
	int	i;
	int	j;

	i = -1;
	while (++i < tcon->total_elements)
	{
		j = i;
		while (++j < tcon->total_elements)
			if (tcon->nbr_arr[i] == tcon->nbr_arr[j])
				return (INVALID);
	}
	return (VALID);
}

static int	normalize_data_in_array(t_ctr *tcon)
{
	int	i;
	int	j;
	int	rank;

	i = -1;
	while (++i < tcon->total_elements)
	{
		rank = 0;
		j = -1;
		while (++j < tcon->total_elements)
			if (tcon->nbr_arr[i] > tcon->nbr_arr[j])
				rank++;
		tcon->norm_arr[i] = rank;
	}
	return (VALID);
}
