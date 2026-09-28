/*

00_pixel/
main.c

*/

#include "MLX42/MLX42.h"

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	mlx = mlx_init(600, 400, "learn_pixel", false);
	if (mlx == NULL)
		return (1);

	image = mlx_new_image(mlx, 600, 400);
	if (image == NULL)
	{
		mlx_terminate(mlx);
		return (1);
	}

	mlx_put_pixel(image, 300, 200, 0xFF0000FF);

	if (mlx_image_to_window(mlx, image, 0, 0) < 0)
	{
		mlx_terminate(mlx);
		return (1);
	}

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

