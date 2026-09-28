/*

02_line/
line.c

*/

#include "graphics.h"

static int	get_direction(int start, int end);

// slope = dy / dx;
int	draw_line(t_graphics *graphics, t_line line_def)
{
	int	x_direction;
	int	y_direction;
	int	dx;
	int	dy;
	int	error;

	dx = abs(line_def.end_x - line_def.start_x);
	dy = abs(line_def.end_y - line_def.start_y);
	x_direction = get_direction(line_def.start_x, line_def.end_x);
	y_direction = get_direction(line_def.start_y, line_def.end_y);
	error = 0;
	while (line_def.start_x != line_def.end_x)
	{
		draw_pixel(graphics, line_def.start_x, line_def.start_y);
		error += dy;
		if (error >= dx)
		{
			line_def.start_y += y_direction;
			error = error - dx;
		}
		line_def.start_x += x_direction;
	}
	draw_pixel(graphics, line_def.end_x, line_def.end_y);
	return (0);
}

/*
	returns 0 if there is no slope - start == end 
*/
static int	get_direction(int start, int end)
{
	if (start < end)
		return (1);
	if (start > end)
		return (-1);
	return (0);
}

/*
|0 1 2 3 4 5 6 7 8
|1
|2	 x
|3    x
|4	   x
|5		x
|6		 x
|7		
|8
|9
|
|
|
*/
