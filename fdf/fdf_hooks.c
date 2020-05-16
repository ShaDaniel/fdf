#include "fdf.h"

static voic	set_default_values(t_main *fdf)
{
	fdf->offset->x = 100;
	fdf->offset->y = 100;
	fdf->map->zscale = 3;
	fdf->map->zoom = 4;
}

static void	arrows_move(t_main *fdf, int keycode)
{
	if (keycode == KEY_UP)
		fdf->offset->y -= 10;
	else if (keycode == KEY_DOWN)
		fdf->offset->y += 10;
	else if (keycode == KEY_LEFT)
		fdf->offset->x -= 10;
	else if (keycode == KEY_RIGHT)
		fdf->offset->x += 10;
}

int			keyboard_hook(int key, void *param)
{
	t_main *fdf;

	fdf = (t_main *)param;
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_I)
		fdf->iso = 1;
	else if (key == KEY_P)
		fdf->iso = 0;
	else if (key == KEY_DOWN || key == KEY_UP || key == KEY_RIGHT || key == KEY_LEFT)
		arrows_move(fdf, key);
	else if (key == KEY_LBRK && fdf->map->zoom > 1)
		fdf->map->zoom--;
	else if (key == KEY_RBRK && fdf->map->zoom < 40)
		fdf->map->zoom++;
	else if (key == KEY_Z && fdf->map->zscale < 20)
		fdf->map->zscale++;
	else if (key == KEY_X && fdf->map->zscale > -20)
		fdf->map->zscale--;
	else if (key == KEY_SPACE)
		set_default_values(fdf);
	else
		return (0);
	fdf_draw_img(fdf);
	return (0);
}