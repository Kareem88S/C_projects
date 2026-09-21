/*

menu_init.c

*/

#include "../../header_files/engine.h"


void		draw_menu(t_engine *engine);

void	menu_init(t_engine *engine)
{
	mlx_image_t	*img;

	img = mlx_new_image(engine->mlx, engine->win_width, engine->win_height);
	if (!img)
		engine_error(engine);
	if (mlx_image_to_window(engine->mlx, img, 0, 0) < 0)
		engine_error(engine);
	engine->img = img;
	// draw_menu(engine);
	draw_pattern(engine);
}

// void	draw_menu(t_engine *engine)	??
