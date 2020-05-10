#include "fdf.h"

static void	fdf_point_set(t_point *p, size_t x, size_t y, t_main *fdf)
{
	p->x = fdf->offset->x + x * DIST_MIN * fdf->map->zoom;
	p->y = fdf->offset->y + y * DIST_MIN * fdf->map->zoom;
	p->z = fdf->map->coords[y * fdf->map->width + x];
	p->colour = fdf->map->colours[y * fdf->map->width + x];
}

static void fdf_draw_pix(t_point *p, t_main *fdf)
{
	size_t		index;
	uint32_t	colour;
	
	index = y * fdf->size_line + x * fdf->bits_per_pixel;
	if (p->x < WIN_WID && p->y < WIN_HGHT)
	{
		colour = p->colour << 8;
		index = p->y * fdf->size_line + p->x * fdf->bits_per_pixel;
		ft_memcpy(&(fdf->data_addr[index]), (const void *)colour, 3);
	}
}

static void	fdf_draw_line(t_point *p1, t_point *p2, t_main *fdf)
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err[2];

	dx = ft_abs(p1->x - p2->x);
	dy = ft_abs(p1->y - p2->y);
	sx = p1->x > p2->x ? -1 : 1;
	sy = p1->y > p2->y ? -1 : 1;
	err[0] = dx + dy;
	while (p1->x != p2->x && p1->y != p2->y)
	{
		fdf_draw_pix(p1, fdf);
		err[1] = err[0] * 2;
		if (err[1] >= dy)
		{
			err[0] += dy;
			p1->x += sx;
		}
		if (err[1] <= dx)
		{
			err[0] += dx;
			p1->y += sy;
		}
	}
}

void		fdf_draw_img(t_main *fdf)
{
	size_t	x;
	size_t	y;
	t_point	*p1;
	t_point *p2;

	x = 0;
	y = 0;
	p1 = (t_point *)ft_memalloc(sizeof(t_point));
	p2 = (t_point *)ft_memalloc(sizeof(t_point));
	while (y < fdf->map->height - 1)
	{
		x = 0;
		while (x < fdf->map->width - 1)
		{
			fdf_point_set(p1, x, y, fdf);
			fdf_point_set(p2, x + 1, y, fdf);
			fdf_draw_line(p1, p2, fdf);
			fdf_point_set(p2, x, y + 1, fdf);
			fdf_draw_line(p1, p2, fdf);
			x++;
		}
		y++;
	}
}