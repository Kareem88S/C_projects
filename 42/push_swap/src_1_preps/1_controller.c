/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:51:30 by kasherif          #+#    #+#             */
/*   Updated: 2025/02/26 02:51:30 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

t_ctr		*preset_tcon(t_ctr *tcon, int ac, char *av[], char ***user_input);
static int	get_user_input(int argc, char *argv[], char ***user_input);
static void	free_input(char ***user_input, int argc);
static char	**parse_user_input(char **str, int words);

/*
Creates two objects: 
	1) the controller-struct; 
	2) the parsed user-input. 
For the user-input, important to distinguish how it is set:
- either parsed from one string (arcg==2), which CREATES (malloc) new strings,
- or copies pointers (argc > 2++). No Malloc.
Later in the program: free each string ONLY if argc == 2.
*/
t_ctr	*preset_tcon(t_ctr *tcon, int argc, char *argv[], char ***user_input)
{
	if (argc < 2)
		return (NULL);
	if (get_user_input(argc, argv, user_input) == INVALID)
		return (NULL);
	tcon = malloc(sizeof(t_ctr));
	if (tcon == NULL)
		return (free_input(user_input, argc), NULL);
	tcon->total_elements = 0;
	while ((*user_input)[tcon->total_elements])
		tcon->total_elements++;
	tcon->nbr_arr = NULL;
	tcon->norm_arr = NULL;
	tcon->nbr_arr = malloc (sizeof(int) * tcon->total_elements);
	tcon->norm_arr = malloc (sizeof(int) * tcon->total_elements);
	if (!(tcon->nbr_arr) || !(tcon->norm_arr))
		return (free_input(user_input, argc), free_all(tcon), NULL);
	tcon->stack_size_a = 0;
	tcon->stack_size_b = 0;
	tcon->a_top = NULL;
	tcon->a_bottom = NULL;
	tcon->b_top = NULL;
	tcon->b_bottom = NULL;
	tcon->count_of_moves = 0;
	return (tcon);
}

static int	get_user_input(int argc, char *argv[], char ***user_input)
{
	if (argc == 2)
	{
		*user_input = ft_split(argv[1], ' ');
		if (*user_input == NULL)
			return (INVALID);
	}
	else if (argc > 2)
	{
		*user_input = parse_user_input(&argv[1], argc - 1);
		if (*user_input == NULL)
			return (INVALID);
	}
	return (VALID);
}

static void	free_input(char ***user_input, int argc)
{
	int	i;

	if (user_input == NULL || *user_input == NULL)
		return ;
	if (argc == 2)
	{
		i = -1;
		while ((*user_input)[++i] != NULL)
		{
			free ((*user_input)[i]);
			(*user_input)[i] = NULL;
		}
	}
	free (*user_input);
	*user_input = NULL;
	return ;
}

static char	**parse_user_input(char **str, int words)
{
	char	**result;
	int		index;

	if (**str != '-' || **str < '0' || **str > '9')
		result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	index = -1;
	while (++index < words)
	{
		result[index] = str[index];
	}
	result[index] = NULL;
	return (result);
}
