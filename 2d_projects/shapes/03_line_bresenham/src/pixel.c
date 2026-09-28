/*

03_line_bresenham/
pixel.c

*/

#include "graphics.h"

// the input struct ought to be replaced eventually by a specified drawing region (like a menu or minimap)
int	draw_pixel(t_graphics *graphics, int x, int y)
{
	if (x < 0 || y < 0)
		return (1);
	if (x >= (int)graphics->image->width
		|| y >= (int)graphics->image->height)
		return (1);
	mlx_put_pixel(graphics->image, x, y, 0xFF0000FF);
	return (0);
}
