/*

03_line_bresenham/
line.c

*/

#include "graphics.h"

static int	get_direction(int start, int end);
static int	draw_line_horizontal(t_graphics *graphics, t_line line);
static int	draw_line_vertical(t_graphics *graphics, t_line line);
static void	swap(int *p1, int *p2);

/*
p aka D. p is the decision variable that tells whether the ideal mathematical 
	line has crossed sufficiently far toward the next pixel. (p = d0 - d1)

*/
int	draw_line(t_graphics *graphics, t_line line_def)
{
	if (abs(line_def.x1 - line_def.x0) > abs(line_def.y1 - line_def.y0))
	{
		if (line_def.x0 > line_def.x1)
		{
			swap(&line_def.x0, &line_def.x1);
			swap(&line_def.y0, &line_def.y1);
		}
		line_def.dx = line_def.x1 - line_def.x0;
		line_def.dy = line_def.y1 - line_def.y0;
		return (draw_line_horizontal(graphics, line_def));
	}
	else
	{
		if (line_def.y0 > line_def.y1)
		{
			swap(&line_def.x0, &line_def.x1);
			swap(&line_def.y0, &line_def.y1);
		}
		line_def.dx = line_def.x1 - line_def.x0;
		line_def.dy = line_def.y1 - line_def.y0;
		return (draw_line_vertical(graphics, line_def));
	}
	return (0);
}

static int	draw_line_vertical(t_graphics *graphics, t_line line)
{
	int	x;
	int	p;
	int	i;

	line.dir = get_direction(line.x0, line.x1);
	line.dx *= line.dir;
	if (line.dy != 0)
	{
		x = line.x0;
		p = 2 * line.dx - line.dy;
		i = 0;
		while (i < line.dy + 1)
		{
			if (draw_pixel(graphics, x, line.y0 + i) != 0)
				return (1);
			if (p >= 0)
			{
				x += line.dir;
				p = p - 2 * line.dy;
			}
			p = p + 2 * line.dx;
			i++;
		}
	}
	return (0);
}

static int	draw_line_horizontal(t_graphics *graphics, t_line line)
{
	int	y;
	int	p;
	int	i;

	line.dir = get_direction(line.y0, line.y1);
	line.dy *= line.dir;
	if (line.dx != 0)
	{
		y = line.y0;
		p = 2 * line.dy - line.dx;
		i = 0;
		while (i < line.dx + 1)
		{
			if (draw_pixel(graphics, line.x0 + i, y) != 0)
				return (1);
			if (p >= 0)
			{
				y += line.dir;
				p = p - 2 * line.dx;
			}
			p = p + 2 * line.dy;
			i++;
		}
	}
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

static void	swap(int *p1, int *p2)
{
	int	temp;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
