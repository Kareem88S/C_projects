/*

03_line_bresenham/
graphics.c

*/

#include "graphics.h"

int	graphics_init(t_graphics *graphics)
{
	graphics->mlx = mlx_init(600, 400, "pixel_refactored", false);
	if (graphics->mlx == NULL)
		return (1);
	return (0);
}

int	graphics_create_image(t_graphics *graphics)
{
	graphics->image = mlx_new_image(graphics->mlx, 600, 400);
	if (graphics->image == NULL)
	{
		mlx_terminate(graphics->mlx);
		return (2);
	}
	return (0);
}

void	graphics_destroy(t_graphics *graphics)
{
	if (graphics->mlx != NULL)
		mlx_terminate(graphics->mlx);
}
