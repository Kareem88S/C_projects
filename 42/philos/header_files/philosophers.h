/*

philosophers.h
8 feb 2026

*/

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
// # include <

# define CHAR_MAX 4

// typedef struct s_simulation t_sim;
// typedef struct s_philosophers_rules_settings_struct t_rules;
// typedef struct s_philosopher_stats t_philo;
// typedef enum e_arg_validation t_error;

typedef enum e_arg_validation
{
	VALID = 0,
	INVALID_ARGS_COUNT,	// args provided insufficient
	INVALID_ARG_VALUE,	// arg provided invalid input
	INSUFFICIENT_PHILOS,// input of just one philosopher
	INSUFFICIENT_MEMORY,// malloc failed
}	t_error;

typedef struct s_philosopher_stats
{
	int	id;
	int	remaining_life;	// in ms
	int	remaining_meal;	// in ms
	int	remaining_sleep;// in ms
	int	eaten_meals;
}	t_philo;

typedef struct s_philosophers_rules_settings_struct
{
	int	no_of_philos;		// number_of_philosophers
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	countdown;		// number_of_times_each_philosopher_must_eat, optional
}	t_rules;

typedef struct s_simulation
{
	t_rules	rules;
	t_philo	*philo_data;
	// mutex
	char	someone_died;
	// start time
}	t_sim;

void	validate_and_store_input(int argc, char **argv, t_sim *sim);
void	create_philos(t_sim *sim);void	finalize_simulation(t_sim *sim);
void	exit_on_error(t_sim *sim, t_error code);
void	finalize_simulation(t_sim *sim);
void	free_all(t_sim *sim);
void	free_and_null(void **end);

#endif