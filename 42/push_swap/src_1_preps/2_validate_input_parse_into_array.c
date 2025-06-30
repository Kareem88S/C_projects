/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_validate_input_parse_into_array.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasherif <kasherif@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:39:57 by kasherif          #+#    #+#             */
/*   Updated: 2025/04/25 16:39:57 by kasherif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/push_swap.h"

int			validate_input_parse_into_array(t_ctr *tcon, int argc,
				char **user_input);
static int	get_word_len(char *current_word);
static long	ft_atol_simplified(const char *nptr, int *fail_safe, int sign);
static void	free_input(char ***user_input, int argc);
static int	is_overflow(long res, int digit, int sign);

#define P 1
#define N -1
#define INT_MIN_DIGITS 11
#define INT_MAX_DIGITS 10

/*
Loops over the user_input strings.
	Counts the amount of chars per string.
	Validates the given chars
	Transforms into int
	Stores in int-array
*/
int	validate_input_parse_into_array(t_ctr *tcon, int argc, char **user_input)
{
	int	cur_nbr;
	int	word_len;
	int	nbr;

	cur_nbr = -1;
	while (++cur_nbr < tcon->total_elements)
	{
		word_len = get_word_len(user_input[cur_nbr]);
		if (word_len == INVALID)
			break ;
		if (*user_input[cur_nbr] == '-')
			nbr = ft_atol_simplified(user_input[cur_nbr], &word_len, N);
		else if (*user_input[cur_nbr] != '-')
			nbr = ft_atol_simplified(user_input[cur_nbr], &word_len, P);
		if (word_len == INVALID)
			break ;
		tcon->nbr_arr[cur_nbr] = nbr;
	}
	free_input(&user_input, argc);
	if (word_len == INVALID)
	{
		error_msg_free_all(tcon);
		return (INVALID);
	}
	return (VALID);
}

/*
INT_MAX can contain 10 chars if positive (2147483647), 
					11 if sign is included. (-2147483648)
Depending on compiler/system could be different.
Everything without returns INVALID. 
*/
static int	get_word_len(char *word)
{
	int	len;

	len = 0;
	if (!word || word[0] == '\0' || (word[0] == '-' && word[1] == '\0'))
		return (INVALID);
	while (word[len] == '-' || ft_isdigit(word[len]))
		len++;
	if (word[len] != '\0')
		return (INVALID);
	if (word[0] == '-')
	{
		if (!ft_isdigit(word[1]))
			return (INVALID);
		if (len > INT_MIN_DIGITS)
			return (INVALID);
		if (len == INT_MIN_DIGITS && word[1] > '2')
			return (INVALID);
	}
	if (word[0] != '-' && len == INT_MAX_DIGITS && word[0] > '2')
		return (INVALID);
	return (len);
}

/*
Adjusted and simplified version of atoi / atol.
Checks for sign or digit, else returns INVALID.
Checks for max by taking away last digit, and if new digit is add > MAX, INVALID
Fail-safe is (irrelevant) word-len. If INVALID, returns word-len == -1 (INVALID)
*/
static long	ft_atol_simplified(const char *nptr, int *fail_safe, int sign)
{
	long	res;
	int		count;
	int		digit;

	if (!nptr || *nptr == '\0' || (*nptr != '-' && !ft_isdigit(*nptr)))
		return ((*fail_safe = INVALID), INVALID);
	res = 0;
	count = 0;
	if (sign == -1 && ++count)
		nptr++;
	while (*nptr != '\0' && ft_isdigit(*nptr))
	{
		digit = (*nptr - '0');
		if (is_overflow(res, digit, sign) == INVALID)
			return ((*fail_safe = INVALID), INVALID);
		res = res * 10 + digit;
		nptr++;
		count++;
	}
	if ((*nptr != '\0' && *nptr != ' ') || (count != *fail_safe))
		return ((*fail_safe = INVALID), INVALID);
	return ((int)res * sign);
}

static void	free_input(char ***user_input, int argc)
{
	int	i;

	if (argc == 2)
	{
		i = -1;
		while ((*user_input)[++i])
		{
			free ((*user_input)[i]);
			(*user_input)[i] = NULL;
		}
	}
	free (*user_input);
	*user_input = NULL;
	return ;
}

static int	is_overflow(long res, int digit, int sign)
{
	if (((res > MAX_INT / 10) || (res == MAX_INT / 10 && digit > MAX_INT % 10))
		&& (sign == 1))
		return (INVALID);
	if (sign == -1 && (res > -(MIN_INT / 10)
			|| (res == -(MIN_INT / 10) && digit > -(MIN_INT % 10))))
		return (INVALID);
	return (0);
}
