/*

error_handling.c
10 feb 2026

*/

#include "philosophers.h"

static void	print_msg(const char *str1, const char *str2);
static void	print_error_message(int error);

void	exit_on_error(t_sim *sim, t_error code)
{
	print_error_message(code);
	if (sim->philo_data) // prob just always free all and check there
		free_all(sim);
	exit(code);
}

static void	print_error_message(int error)
{
	const char	*memory = "Insufficient memory.\n";
	const char	*usage = "Usage: ./program arg1 arg2 arg3 arg4 [arg5]\n\
	program	== philosophers\n\
	arg1 	== number_of_philosophers\n\
	arg2 	== time_to_die\n\
	arg3 	== time_to_eat\n\
	arg4 	== time_to_sleep\n\
	arg5 	== [optional] [number_of_times_each_philosopher_must_eat]\n";
	const char	*arg_no = "Invalid number of arguments\n";
	const char	*arg_value = \
	"Invalid arguments' value: expected all integers. Capped at 9.999\n";
	const char	*more_philos = \
	"Expected more then one philosopher.\n";

	if (error == INSUFFICIENT_MEMORY)
		print_msg(memory, NULL);
	if (error == INVALID_ARGS_COUNT)
		print_msg(arg_no, usage);
	if (error == INVALID_ARG_VALUE)
		print_msg(arg_value, usage);
	if (error == INSUFFICIENT_PHILOS)
		print_msg(more_philos, usage);
}

static void	print_msg(const char *str1, const char *str2)
{
	int	len;

	len = 0;
	while (str1[len])
		len++;
	write (1, str1, len);
	if (!str2)
		return ;
	len = 0;
	while (str2[len])
		len++;
	write (1, str2, len);
}
