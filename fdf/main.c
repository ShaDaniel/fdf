#include "fdf.h"

int		main(int ac, char **av)
{
	t_main	*fdf;

	if (ac != 2)
		fdf_error(EUSE);
	fdf_init(&fdf);
	fdf_parse_map(fdf, av[1]);
	return (0);
}
