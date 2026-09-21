/*

render.h

*/

#ifndef RENDER_H
# define RENDER_H

#include <stdint.h>

typedef struct s_render_surface
{
    uint32_t    *pixels;
    int         width;
    int         height;
}   t_canvas;

typedef struct s_pixel_color
{
    uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
	uint8_t	alpha;
}   t_color;

uint32_t	color_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

#endif