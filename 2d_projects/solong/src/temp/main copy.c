// main.c

#include "../header_files/so_long.h"

static void	ft_error(t_game *game);


int	main(void)
{
	t_game	*game;

	game = init_game_struct(NULL);
	init_window(game);
	init_main_image(game);
	start_loop(game);
	destroy_game(game);
	return (0);
}

t_game	*init_game_struct(t_game *game)
{
	game = malloc(sizeof(t_game));
	if (!game)
		ft_error(NULL);
	game->mlx = NULL;
	game->img = NULL;
	return (game);
}

/* Optional fullscreen:
mlx_set_setting(MLX_MAXIMIZED, true);

NB
game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
true == resizable, false  == not resizable
*/
void	init_window(t_game *game)
{
	game->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "so_long", true);
	if (!game->mlx)
		ft_error(game);
}

#include <string.h>
void	init_main_image(t_game *game)
{
	mlx_image_t	*img;

	img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img)
		ft_error(game);
	memset(img->pixels, 100, 256 * img->height * BPP);
	if (mlx_image_to_window(game->mlx, img, 0, 0) < 0)
		ft_error(game);
	game->img = img;
}
// void	init_main_image(t_game *game)
// {
// 	mlx_image_t	*img;

// 	img = mlx_new_image(game->mlx, 256, 256);
// 	if (!img)
// 		ft_error(game);
// 	memset(img->pixels, 255, img->width * img->height * BPP);
// 	if (mlx_image_to_window(game->mlx, img, 0, 0) < 0)
// 		ft_error(game);
// 	game->img = img;
// }
// void	init_main_image(t_game *game)
// {
// 	mlx_image_t	*img;

// 	img = mlx_new_image(game->mlx, 256, 256);
// 	if (!img)
// 		ft_error(game);
// 	if (mlx_image_to_window(game->mlx, img, 0, 0) < 0)
// 		ft_error(game);
// 	game->img = img;
// }

void	start_loop(t_game *game)
{
	mlx_loop(game->mlx);
}

void	destroy_game(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx)
		mlx_terminate(game->mlx);
	free(game);
}

// Exit the program as failure.
static void	ft_error(t_game *game)
{
	if (game)
	{
		if (game->mlx)
			mlx_terminate(game->mlx);
		free(game);
	}
	fprintf(stderr, "%s\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}



// int	main(void)
// {
// 	t_game		*game;
// 	mlx_image_t	*img;
	
// 	game = malloc(sizeof(t_game));
// 	if (!game)
// 		return (ft_error(NULL), 1);
	
// 	// if FULL SCREEN
// 	// mlx_set_setting(MLX_MAXIMIZED, true);
// 	game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true); // true == resizable, false  == not resizable
// 	if (!game->mlx)
// 		return (ft_error(game), 2);
// 	// Create and display the image.
// 	img = mlx_new_image(game->mlx, 256, 256);
// 	if (!img || (mlx_image_to_window(game->mlx, img, 0, 0) < 0))
// 		return (ft_error(game), 3);
		
// 	mlx_loop(game->mlx);
// 	mlx_terminate(game->mlx);

// 	free(game);
// 	return (0);
// }



		// typedef struct s_game
		// {
		// 	mlx_t			*mlx;
		// }	t_game;


		// typedef struct mlx
		// {
		// 	void*		window;
		// 	void*		context;
		// 	int32_t		width;
		// 	int32_t		height;
		// 	double		delta_time;
		// }	mlx_t;


// t_game	g_game;

// int	main(void)
// {
// 	g_game.mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
// 	if (!g_game.mlx)
// 	{
// 		fprintf(stderr, "%s\n", mlx_strerror(mlx_errno));
// 		return (EXIT_FAILURE);
// 	}
// 	mlx_image_t	*img;

// 	img = mlx_new_image(g_game.mlx, WIDTH, HEIGHT);
// 	if (!img)
// 	{
// 		fprintf(stderr, "%s\n", mlx_strerror(mlx_errno));
// 		mlx_terminate(g_game.mlx);
// 		return (EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(g_game.mlx, img, 0, 0) < 0)
// 	{
// 		fprintf(stderr, "%s\n", mlx_strerror(mlx_errno));
// 		mlx_delete_image(g_game.mlx, img);
// 		mlx_terminate(g_game.mlx);
// 		return (EXIT_FAILURE);
// 	}

// 	mlx_loop(g_game.mlx);
// 	mlx_terminate(g_game.mlx);
// 	return (EXIT_SUCCESS);
// }
