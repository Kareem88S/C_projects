/*

03_line_bresenham/
main.c

*/

#include "graphics.h"

int	main(void)
{
	t_graphics	graphics;
	t_line		line_definition;

	if (graphics_init(&graphics))
		return (1);
	if (graphics_create_image(&graphics))
	{
		graphics_destroy(&graphics);
		return (2);
	}
	line_definition.x0 = 220;
	line_definition.y0 = 0;
	line_definition.x1 = 30;
	line_definition.y1 = 200;
	if (draw_line(&graphics, line_definition) != 0)
		return (3);
	if (mlx_image_to_window(graphics.mlx, graphics.image, 0, 0) < 0)
	{
		mlx_terminate(graphics.mlx);
		return (1);
	}
	mlx_loop(graphics.mlx);
	mlx_terminate(graphics.mlx);
	return (0);
}
