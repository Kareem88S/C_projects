/*

color.c

*/

#include "../../header_files/render.h"

uint32_t	color_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return ((uint32_t)a << 24
          | (uint32_t)b << 16
          | (uint32_t)g << 8
          | (uint32_t)r);
}

// // 0xAARRGGBB
// uint32_t	color_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
// {
// 	uint32_t	color;

// 	color = 0;
// 	color |= ((uint32_t)a << 24);
// 	color |= ((uint32_t)r << 16);
// 	color |= ((uint32_t)g << 8);
// 	color |= (uint32_t)b;
// 	return (color);
// }