/*

validate_input.c
8 feb 2026

*/

#include "philosophers.h"

static int	convert_input(int argc, char **argv, t_rules *set_rules);
static int	conversion(char *str, int *valid);

void	validate_and_store_input(int argc, char **argv, t_sim *sim)
{
	int	validation;

	if (argc < 5 || argc > 6)
		exit_on_error(sim, INVALID_ARGS_COUNT);
	validation = convert_input(argc, argv, &(sim->rules));
	if (validation != VALID)
		exit_on_error(sim, validation);
	return ;
}

static int	convert_input(int argc, char **argv, t_rules *set_rules)
{
	int	valid;

	valid = VALID;
	set_rules->no_of_philos = conversion(argv[1], &valid);
	if (set_rules->no_of_philos <= 1)
		valid = INSUFFICIENT_PHILOS;
	set_rules->time_to_die = conversion(argv[2], &valid);
	set_rules->time_to_eat = conversion(argv[3], &valid);
	set_rules->time_to_sleep = conversion(argv[4], &valid);
	if (argc == 6)
		set_rules->countdown = conversion(argv[5], &valid);
	else
		set_rules->countdown = 0;
	return (valid);
}

static int	conversion(char *str, int *valid)
{
	int	str_len;
	int	value;
	int	pow;

	if (*valid != VALID)
		return (-1);
	str_len = 0;
	value = 0;
	pow = 1;
	while (*str != '\0')
	{
		if (str_len > CHAR_MAX || *str < '0' || *str > '9')
		{
			*valid = INVALID_ARG_VALUE;
			return (*valid);
		}
		value = value + ((*str) - '0') * pow;
		pow *= 10;
		str_len++;
		str++;
	}
	return (value);
}
