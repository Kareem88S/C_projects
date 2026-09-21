/*

engine.h

*/

#ifndef ENGINE_H
# define ENGINE_H

# include "MLX42/MLX42.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define MENU_WIN_WD 600
# define MENU_WIN_HT 400
// # define WIN_WIDTH 1024
// # define WIN_HEIGHT 512
# define BPP sizeof(int32_t)	// bits per pixel

typedef struct s_engine
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			win_width;
	int			win_height;
	char		*window;
	int			window_resizable;
	int			is_fullscreen;
}	t_engine;

t_engine	*engine_create(void);
void		engine_window_create(t_engine *engine);
void		scene_menu_init(t_engine *engine);
void		engine_loop(t_engine *engine);
void		engine_destroy(t_engine *engine);
void		engine_error(t_engine *engine);

#endif
