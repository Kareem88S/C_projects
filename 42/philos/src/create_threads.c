/*

create_threads.c
10 feb 2026

*/

#include "philosophers.h"

void	create_philos(t_sim *sim)
{
	int			i;
	pthread_t 	philo[sim->rules.no_of_philos];

	// maybe relocate to mem-management
	sim->philo_data = malloc(sizeof(t_philo) * sim->rules.no_of_philos);
	if (sim->philo_data == NULL)
		exit_on_error(sim, INSUFFICIENT_MEMORY);
	i = 0;
	while (i < sim->rules.no_of_philos)
	{
	// <%	// digraphs
		sim->philo_data[i].id = 0; 
		sim->philo_data[i].remaining_life = sim->rules.time_to_die;
		sim->philo_data[i].remaining_meal = sim->rules.time_to_eat;
		sim->philo_data[i].remaining_sleep = sim->rules.time_to_sleep;
		sim->philo_data[i].eaten_meals = 0; 
		i++;
	// %>
	}
	(void) philo;

	return ;
}