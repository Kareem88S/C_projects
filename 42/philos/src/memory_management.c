/*

memory_management.c
10 feb 2026

*/

#include "philosophers.h"

void	free_all(t_sim *sim)
{
	(void) sim;
	if (sim->philo_data)
	{
		free_and_null((void **) &sim->philo_data);

	}
	return ;
}

void	free_and_null(void **end)
{
	free(*end);
	(*end) = NULL;
}
