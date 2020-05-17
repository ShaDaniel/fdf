#include "fdf.h"

static void	fdf_point_set(size_t x, size_t y, t_main *fdf)
{
	int	old_x;
	int	old_y;

	fdf->map->p1->x = fdf->offset->x + x * DIST_MIN * fdf->map->zoom;
	fdf->map->p1->y = fdf->offset->y + y * DIST_MIN * fdf->map->zoom;
	fdf->map->p1->z = (fdf->map->coords[y * fdf->map->width + x] - fdf->map->min_z) *
		fdf->map->zscale * fdf->map->zoom;
	fdf->map->p1->colour_s = fdf->map->colours[y * fdf->map->width + x] & 0xFFFFFF;
	fdf->map->p1->colour_f = WHITE;
	if (!fdf->map->p1->colour_s)
		fdf->map->p1->colour_s = WHITE;
	fdf->map->p1->colour_f = fdf->map->p2->colour_s;
	if (fdf->iso)
	{
		old_x = fdf->map->p1->x - fdf->offset->x;
		old_y = fdf->map->p1->y - fdf->offset->y;

		fdf->map->p1->x = (old_x - old_y) * cos(0.8) + fdf->offset->x;
		fdf->map->p1->y = (old_x + old_y) * sin(0.8) - fdf->map->p1->z + fdf->offset->y;
	}
	fdf->map->p1->clr_growth = 1.0 / (DIST_MIN * fdf->map->zoom);
	fdf->map->p1->curr_growth = 0;
	printf("%zuu %zuu", fdf->map->p1->x, fdf->map->p1->y);
}

static void fdf_draw_pix(t_point *p, t_main *fdf)
{
	size_t		index;
	int			colour;
	
	if (p->x >= 0 && p->x < WIN_WID && p->y >= 0 && p->y < WIN_HGHT)
	{
		index = p->y * fdf->size_line + p->x * (fdf->bits_per_pixel / 8);
		colour = mlx_get_color_value(fdf->mlx, fdf_colour_get(p));
		fdf->data_addr[index] = colour;
		fdf->data_addr[index + 1] = colour >> 8;
		fdf->data_addr[index + 2] = colour >> 16;
	}
}

static void	fdf_draw_line(t_point *p1, t_point *p2, t_main *fdf)
{
	int		dx;
	int		dy;
	int		s[2];
	int		err[2];

	dx = ft_abs(p1->x - p2->x);
	dy = ft_abs(p1->y - p2->y);
	s[0] = p1->x < p2->x ? 1 : -1;
	s[1] = p1->y < p2->y ? 1 : -1;
	err[0] = dx - dy;
	while (p1->x != p2->x || p1->y != p2->y)
	{
		fdf_draw_pix(p1, fdf);
		err[1] = err[0] * 2;
		if (err[1] >= -dy)
		{
			err[0] -= dy;
			p1->x += s[0];
		}
		if (err[1] <= dx)
		{
			err[0] += dx;
			p1->y += s[1];
		}
	}
}

void		fdf_draw_img(t_main *fdf)
{
	int	x;
	int	y;

	y = -1;
	ft_memset(fdf->data_addr, 0, fdf->size_line * WIN_HGHT);
	while ((size_t)++y < fdf->map->height)
	{
		x = -1;
		while ((size_t)++x < fdf->map->width)
		{
			if ((size_t)x < fdf->map->width - 1)
			{
				fdf_point_set(x + 1, y, fdf);
				fdf_point_set(x, y, fdf);
				fdf_draw_line(fdf->map->p1, fdf->map->p2, fdf);
			}
			if ((size_t)y < fdf->map->height - 1)
			{
				fdf_point_set(x, y + 1, fdf);
				fdf_point_set(x, y, fdf);
				fdf_draw_line(fdf->map->p1, fdf->map->p2, fdf);
			}
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
