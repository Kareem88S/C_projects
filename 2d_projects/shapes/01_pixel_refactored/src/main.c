/*

01_pixel_refactored/
main.c

*/

#include "graphics.h"

int	main(void)
{
	t_graphics	graphics;

	if (graphics_init(&graphics))
		return (1);
	if (graphics_create_image(&graphics))
	{
		graphics_destroy(&graphics);
		return (2);
	}

	if (draw_pixel(&graphics, 100, 300))
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

