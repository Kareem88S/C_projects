/*

03_line_bresenham/
line.h

*/

#ifndef LINE_H
# define LINE_H

typedef struct s_line
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	dx;
	int	dy;
	int	dir;
}	t_line;

#endif