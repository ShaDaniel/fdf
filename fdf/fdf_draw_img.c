#include "fdf.h"

static void	fdf_point_set(t_point *p, t_point *fin, size_t x, size_t y, t_main *fdf)
{
	int	old_x;
	int	old_y;

	p->x = fdf->offset->x + x * DIST_MIN * fdf->map->zoom;
	p->y = fdf->offset->y + y * DIST_MIN * fdf->map->zoom;
	p->z = fdf->map->coords[y * fdf->map->width + x] * fdf->map->zscale;
	p->colour_s = (int)fdf->map->colours[y * fdf->map->width + x];
	ft_putnbr(p->colour_s);
	if (fin)
		p->colour_f = fin->colour_s;
	if (fdf->iso)
	{
		old_x = p->x;
		old_y = p->y;

		p->x = (old_x - old_y) * cos(0.8);
		p->y = (old_x + old_y) * sin(0.8) - p->z;
	}
}

static void	balance_colours(double *red, double *green, double *blue)
{
	if (*red < 0.04)
		*red += 0.03;
	if (*green < 0.04)
		*green += 0.03;
	if (*blue < 0.04)
		*blue += 0.03;
	if (*red > 0.95)
		*red -= 0.04;
	if (*green > 0.95)
		*green -= 0.04;
	if (*blue > 0.95)
		*blue -= 0.04;
}

static int	fdf_colour_get(t_point *p, t_main *fdf)
{
	double	red_coeff;
	double	green_coeff;
	double	blue_coeff;

	if (!p->colour_s)
		p->colour_s = WHITE;
	if (!p->colour_f)
		p->colour_f = WHITE;
	red_coeff = (double)(((p->colour_f >> 16) & 0xFF) - ((p->colour_s >> 16) & 0xFF)) / (double)((p->colour_f >> 16) & 0xFF);
	green_coeff = (double)(((p->colour_f >> 8) & 0xFF) - ((p->colour_s >> 8) & 0xFF)) / (double)((p->colour_f >> 8) & 0xFF);
	blue_coeff = (double)((p->colour_f & 0xFF) - (p->colour_s & 0xFF)) / (double)(p->colour_f & 0xFF);
	balance_colours(&red_coeff, &green_coeff, &blue_coeff);
	if (p->colour_f == WHITE)
	{
		printf("\n%i %i %f\n", ((p->colour_f >> 16) & 0xFF), ((p->colour_s >> 16) & 0xFF), red_coeff);
	}
	p->colour_s = ((int)(((p->colour_s >> 16) & 0xFF) * red_coeff\
				 + ((p->colour_f >> 16) & 0xFF) * (1 - red_coeff)) << 16) |\
				 ((int)(((p->colour_s >> 8) & 0xFF) * green_coeff\
				 + ((p->colour_f >> 8) & 0xFF) * (1 - green_coeff)) << 8) |\
				 (int)(((p->colour_s & 0xFF) * blue_coeff\
				 + (p->colour_f & 0xFF) * (1 - blue_coeff)));
	return (p->colour_s);
}

static void fdf_draw_pix(t_point *p, t_main *fdf)
{
	size_t		index;
	int			colour;
	
	if (p->x >= 0 && p->x < WIN_WID && p->y >= 0 && p->y < WIN_HGHT)
	{
		index = p->y * fdf->size_line + p->x * (fdf->bits_per_pixel / 8);
		colour = mlx_get_color_value(fdf->mlx, fdf_colour_get(p, fdf));
		fdf->data_addr[index] = colour;
		fdf->data_addr[index + 1] = colour >> 8;
		fdf->data_addr[index + 2] = colour >> 16;
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
	sx = p1->x < p2->x ? 1 : -1;
	sy = p1->y < p2->y ? 1 : -1;
	err[0] = dx - dy;
	while (p1->x != p2->x || p1->y != p2->y)
	{
		fdf_draw_pix(p1, fdf);
		err[1] = err[0] * 2;
		if (err[1] >= -dy)
		{
			err[0] -= dy;
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
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x < fdf->map->width - 1)
			{
				fdf_point_set(p2, NULL, x + 1, y, fdf);
				fdf_point_set(p1, p2, x, y, fdf);
				fdf_draw_line(p1, p2, fdf);
			}
			if (y < fdf->map->height - 1)
			{
				fdf_point_set(p2, NULL, x, y + 1, fdf);
				fdf_point_set(p1, p2, x, y, fdf);
				fdf_draw_line(p1, p2, fdf);
			}
			x++;
		}
		y++;
	}
	free(p1);
	free(p2);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}