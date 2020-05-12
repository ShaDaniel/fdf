#include "fdf.h"

int		keyboard_hook(int keycode, void *param)
{
	t_main *fdf;

	fdf = (t_main *)param;
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_I)
		fdf->iso = 1;
	else if (keycode == KEY_P)
		fdf->iso = 0;
	else if (keycode == KEY_UP)
		fdf->offset->y -= 10;
	else if (keycode == KEY_DOWN)
		fdf->offset->y += 10;
	else if (keycode == KEY_LEFT)
		fdf->offset->x -= 10;
	else if (keycode == KEY_RIGHT)
		fdf->offset->x += 10;
	else if (keycode == KEY_LBRK && fdf->map->zoom > 1)
		fdf->map->zoom--;
	else if (keycode == KEY_RBRK && fdf->map->zoom < 40)
		fdf->map->zoom++;
	else if (keycode == KEY_Z && fdf->map->scale < 40)
		fdf->map->zscale++;
	else if (keycode == KEY_X && fdf->map->zoom > 1)
		fdf->map->zscale--;
	
	ft_memset(fdf->data_addr, 0, fdf->size_line * WIN_HGHT);
	fdf_draw_img(fdf);
	return (0);
}