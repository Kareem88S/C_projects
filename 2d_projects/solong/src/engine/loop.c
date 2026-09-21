/*

loop.c

*/

#include "../../header_files/engine.h"

void	engine_loop(t_engine *engine)
{
	if (!engine || !engine->mlx)
		return ;
	// mlx_loop_hook(engine->mlx, core_loop, engine);
	mlx_loop(engine->mlx);
}
