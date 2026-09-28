/*

03_line_bresenham/
graphics.h

*/

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "MLX42/MLX42.h"
# include "line.h"

typedef struct s_graphics
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_graphics;

int		graphics_init(t_graphics *graphics);
int		graphics_create_image(t_graphics *graphics);
int		draw_pixel(t_graphics *graphics, int x, int y);
int		draw_line(t_graphics *graphics, t_line line_definition);
void	graphics_destroy(t_graphics *graphics);
int		abs(int num);	// to be replaced by my lib

#endif
