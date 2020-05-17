/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 20:56:01 by marvin            #+#    #+#             */
/*   Updated: 2020/05/17 20:56:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_default_values(t_main *fdf)
{
	fdf->offset->x = 200;
	fdf->offset->y = 200;
	fdf->map->zscale = 1;
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

static void	check_esc_key(int key)
{
	if (key == KEY_ESC)
		exit(0);
}

int			keyboard_hook(int key, void *param)
{
	t_main *fdf;

	fdf = (t_main *)param;
	check_esc_key(key);
	if (key == KEY_I)
		fdf->iso = 1;
	else if (key == KEY_P)
		fdf->iso = 0;
	else if (key == KEY_DOWN || key == KEY_UP ||
			key == KEY_RIGHT || key == KEY_LEFT)
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
