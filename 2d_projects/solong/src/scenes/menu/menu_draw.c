/*

menu_draw.c

*/

void	menu_draw(t_engine *engine)
{
	(void)engine;
}

// moet ook elders
void	draw_pattern(t_engine *engine)
{
	int		i;
	int		j;
	uint8_t	red;
	uint8_t	blue;
	uint8_t	green;
	
	red = 0;
	blue = 255;
	green = 0;
	i = -1;
	while (++i < MENU_WIN_WD)
	{
		j = -1;
		while (++j < MENU_WIN_HT)
		{
			put_pixel(engine->img, i, j, color_rgba(red, green, blue, 255));
			red++;
		}
		blue++;
		red = i;
	}
}

