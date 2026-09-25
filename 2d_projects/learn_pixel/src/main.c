/*

main.c

*/

#include "MLX42/MLX42.h"

int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(600, 400, "learn_pixel", false);
	if (mlx == NULL)
		return (1);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
