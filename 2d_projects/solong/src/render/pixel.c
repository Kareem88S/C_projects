/*

pixel.c

*/

void	put_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
	uint32_t	*pixels;
	uint32_t	index;

	if (img == NULL)
		return ;
	if (x < 0 || y < 0)
		return ;
	if (x >= (int)img->width || y >= (int)img->height)
		return ;

	pixels = (uint32_t *)img->pixels;
	index = y * img->width + x;
	pixels[index] = color;
}

