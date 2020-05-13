#include "fdf.h"

int		main(int ac, char **av)
{
	t_main	*fdf;
	int		fd;

	if (ac != 2)
		fdf_error(EUSE);
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		perror("fdf: ");
		return (0);
	}
	fdf_init(&fdf);
	fdf_parse_map(fd, fdf);
	//fdf_draw_img(fdf);
//	mlx_key_hook(fdf->win, keyboard_hook, fdf);
//	mlx_loop(fdf->mlx);
	return (0);
}
