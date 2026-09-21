/*

window.c

*/

#include "../../header_files/engine.h"

/* Optional fullscreen:
mlx_set_setting(MLX_MAXIMIZED, true);

NB
engine->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
true == resizable, false  == not resizable
*/
void	engine_window_create(t_engine *engine)
{
	engine->mlx = mlx_init(MENU_WIN_WD, MENU_WIN_HT, "so_long", true);
	if (!engine->mlx)
		engine_error(engine);
	// engine->win_width = MENU_WIN_WD;
	// engine->win_height = MENU_WIN_HT;
	engine->win_width = engine->mlx->width;
	engine->win_height = engine->mlx->height;

	// engine->is_fullscreen = 1;	komt later pas
}

