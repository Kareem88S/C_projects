/*

main.c
8 feb 2026

*/

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_sim sim;

	validate_and_store_input(argc, argv, &sim);
	create_philos(&sim);

	// destroy_philos(&sim);
	// finalize_simulation(&sim);

	return (0);
}

// void	destroy_philos(t_sim *sim)
// {

// }

// // location: memory management?
// // maybe todo: print summary
// void	finalize_simulation(t_sim *sim)
// {
// 	free_all(sim);
// }