/*

life_cycle.c

*/

#include "../../header_files/engine.h"

t_engine	*engine_create(void)
{
	t_engine	*engine;

	engine = malloc(sizeof(t_engine));
	if (!engine)
		engine_error(NULL);
	engine->mlx = NULL;
	engine->img = NULL;
	engine->win_width = 0;
	engine->win_height = 0;
	engine->is_fullscreen = 0;
	return (engine);
}

void	engine_destroy(t_engine *engine)
{
	if (!engine)
		return ;
	if (engine->mlx)
		mlx_terminate(engine->mlx);
	free(engine);
}

