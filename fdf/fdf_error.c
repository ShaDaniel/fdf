#include "fdf.h"

void	fdf_error(char *error)
{
	ft_putstr_fd(error, 2);
	exit(255);
}