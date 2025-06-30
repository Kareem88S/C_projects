/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:15:08 by kasherif          #+#    #+#             */
/*   Updated: 2025/02/18 00:15:08 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ATTENTIE:
// g_moves in 4_print_operation.c  	!!!! Global

#include "header_files/push_swap.h"

void	print_list(t_ctr *tcon);

int g_moves = 0;

int	main(int argc, char *argv[])
{
	t_ctr	*tcon;
	char	**user_input;
	
	tcon = preset_tcon(NULL, argc, argv, &user_input);
	if (tcon == NULL)
		return (INVALID);
	if (validate_input_parse_into_array(tcon, argc, user_input) == INVALID)
		return (INVALID);
	if (validate_dups_and_normalize_values(tcon) == INVALID)
		return (INVALID);
	if (parse_into_circ_linked_list(tcon) == INVALID)
		return (INVALID);
	update_global_state(tcon);
	
	print_list(tcon);
	sorting_manager(tcon, &(tcon->a_top), tcon->total_elements, NULL);
	// sorting_manager(tcon, &(tcon->a_top), &(tcon->b_top), tcon->total_elements);
	print_list(tcon);
	printf("\nmoves: %i\n", g_moves);
	free_all(tcon);
	

	return (0);
}



void	print_list(t_ctr *tcon)
{
	int	i;
	t_n	*current;

	i = 0;
	current = tcon->a_top;
	if (!current)
		return ;
	// while (i < tcon->total_elements && current != current->previous)
	do
	{
		// printf("Item %i: %lli -- Relative: %i\n", i + 1, current->actual_value, current->normalized_value);
		printf("Norm %i\n", current->normalized_value);
		current = current->previous;
		i++;
	} while (current != tcon->a_top);
}



//	*** SORTED ***
// if (tcon->relative_value == INVALID && tcon->stack_size == 1)
// 	// then list is sorted (only 1 element)
// 		**** ****

// oiud kan wellicht weg

// swap algo ( voor ints )
// 	int	a;
// 	int	b;

// 	a = 10;
// 	b = 33;
// 	printf("%i & %i \n", a, b);
// 	a ^= b;
// 	b ^= a;
// 	a ^= b;
// 	// BIN_SWAP(a, b);
// 	printf("%i & %i \n", a, b);
// }



