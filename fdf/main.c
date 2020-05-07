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
	return (0);
}
