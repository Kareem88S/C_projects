// main.c

#include "../header_files/so_long.h"

// void resize_hook(int32_t width, int32_t height, void *param);
// void mlx_resize_hook(mlx_t* mlx, mlx_resizefunc func, void* param);


int	main(void)
{
	t_engine	*engine;

	engine = engine_create();
	engine_window_create(engine);
	scene_menu_init(engine);
	engine_loop(engine);
	engine_destroy(engine);
	return (0);
}

// 	// set bg to red
// 	// draw_bg(img, 0xFF5555C5); // Red
// 	ks_put_pixel(img, img->width, img->height, 0xFF00FF55);	// err out of bounds
// 	ks_put_pixel(img, img->width - 1, img->height, 0xFF00FF55); // err
// 	ks_put_pixel(img, img->width - 2, img->height, 0xFF00FF55); // err
// 	ks_put_pixel(img, img->width - 3, img->height, 0xFF00FF55); // err
// 	ks_put_pixel(img, img->width, img->height - 1, 0xFF00FF55); // err
// 	ks_put_pixel(img, img->width, img->height - 2, 0xFF00FF55); // err
// 	ks_put_pixel(img, img->width, img->height - 3, 0xFF00FF55); // err
// 	ks_put_pixel(img, img->width - 1, img->height - 1, 0xFF00FF55);
// 	ks_put_pixel(img, img->width - 2, img->height - 1, 0xFF00FF55);
// 	ks_put_pixel(img, img->width - 3, img->height - 1, 0xFF00FF55);
// 	ks_put_pixel(img, img->width - 1, img->height - 2, 0xFF00FF55);
// 	ks_put_pixel(img, img->width - 2, img->height - 2, 0xFF00FF55);
// 	ks_put_pixel(img, img->width - 3, img->height - 2, 0xFF00FF55);
// 	ks_put_pixel(img, img->width - 1, img->height - 3, 0xFF00FF55);
// 	ks_put_pixel(img, img->width - 2, img->height - 3, 0xFF00FF55);
// 	ks_put_pixel(img, img->width - 3, img->height - 3, 0xFF00FF55);



// void	draw_bg(mlx_image_t *img, uint32_t color)
// {
// 	uint32_t	*pixels;
// 	uint32_t	i;
// 	uint32_t	total;

// 	pixels = (uint32_t *)img->pixels;
// 	total = img->width * img->height;
// 	i = 0;
// 	while (i < total)
// 	{
// 		pixels[i] = color;
// 		i++;
// 	}
// }

// void	ks_put_pixel(mlx_image_t *img, int x, int y, uint32_t color)
// {
// 	uint32_t	*pixels;
// 	uint32_t	index;

// 	if (img == NULL)
// 		return ;
// 	if (x < 0 || y < 0)
// 		return ;
// 	if (x >= (int)img->width || y >= (int)img->height)
// 		return ;

// 	pixels = (uint32_t *)img->pixels;
// 	index = y * img->width + x;
// 	pixels[index] = color;
// }


