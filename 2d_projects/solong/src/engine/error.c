/*

error.c

*/

#include "../../header_files/engine.h"

// Exit the program as failure.
void	engine_error(t_engine *engine)
{
	if (engine)
	{
		if (engine->mlx)
			mlx_terminate(engine->mlx);
		free(engine);
	}
	fprintf(stderr, "%s\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
