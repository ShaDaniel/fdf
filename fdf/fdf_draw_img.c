#include "fdf.h"

void	fdf_draw_img(t_main *fdf)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < fdf->map->height - 1)
	{
		x = 0;
		while (x < fdf->map->width - 1)
		{
			fdf_draw_line()
			x++;
		}
		y++;
	}
}