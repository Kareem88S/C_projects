/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_normalizing_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:12:14 by kasherif          #+#    #+#             */
/*   Updated: 2025/06/23 21:22:08 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

int			normalize_array(int *normalized, int *original, int stack_size);
static void	copy_values(int *dst, int *src, int size);
static void	sort_array(int *arr, int size);
static int	find_index(int *arr, int size, int value);

int	normalize_array(int *normalized, int *original, int stack_size)
{
	int	*sorted;
	int	i;

	sorted = malloc(sizeof(int) * stack_size);
	if (!sorted)
		return (INVALID);
	copy_values(sorted, original, stack_size);
	sort_array(sorted, stack_size);
	i = -1;
	while (++i < stack_size)
	{
		normalized[i] = find_index(sorted, stack_size, original[i]);
		if (normalized[i] == INVALID)
		{
			free_and_null((void **) &sorted);
			return (INVALID);
		}
	}
	free_and_null((void **) &sorted);
	return (VALID);
}

static void	copy_values(int *dst, int *src, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		dst[i] = src[i];
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

static int	find_index(int *arr, int size, int value)
{
	int	i;

	i = -1;
	while (++i < size)
		if (arr[i] == value)
			return (i);
	return (INVALID);
}
