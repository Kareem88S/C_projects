/*

02_line/
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
	line_definition.start_x = 620;
	line_definition.start_y = 0;
	line_definition.end_x = 30;
	line_definition.end_y = 400;
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
