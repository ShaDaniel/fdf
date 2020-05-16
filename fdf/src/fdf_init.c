// #include "../inc/fdf.h"	// TODO
#include "fdf.h"

size_t	get_index_last_coords(char **coords)	//! check this
{
	size_t i;

	i = 0;
	while (coords[i])
		i++;
	return (i);
}

void	fdf_default_values(t_main **fdf)
{
	(*fdf)->map->width = 0;
	(*fdf)->map->height = 0;
	(*fdf)->map->total = 0;
	(*fdf)->map->colours = NULL;
	(*fdf)->map->coords = NULL;
	(*fdf)->offset->x = 200;
	(*fdf)->offset->y = 200;
	(*fdf)->map->zscale = 3;
	(*fdf)->map->zoom = 4;
	(*fdf)->map->max_z = 0;
	(*fdf)->map->min_z = 0;
	(*fdf)->map->p1 = (t_point *)ft_memalloc(sizeof(t_point));
	(*fdf)->map->p2 = (t_point *)ft_memalloc(sizeof(t_point));
}

void	fdf_init(t_main **fdf)
{
	if (!(*fdf = (t_main *)ft_memalloc(sizeof(t_main))))
		fdf_error(EMEM);
	if (!((*fdf)->map = (t_map *)ft_memalloc(sizeof(t_map))))
		fdf_error(EMEM);
	if (!((*fdf)->offset = (t_offset *)ft_memalloc(sizeof(t_offset))))
		fdf_error(EMEM);
	fdf_default_values(fdf);
	if (!((*fdf)->mlx = mlx_init()))
		fdf_error(EMLX);
	if (!((*fdf)->win =
		mlx_new_window((*fdf)->mlx, WIN_WID, WIN_HGHT, PRG_NAME)))
		fdf_error(EMLX);
	if (!((*fdf)->img = mlx_new_image((*fdf)->mlx, WIN_WID, WIN_HGHT)))
		fdf_error(EMLX);
	if (!((*fdf)->data_addr = mlx_get_data_addr((*fdf)->img,
		&((*fdf)->bits_per_pixel), &((*fdf)->size_line), &((*fdf)->endian))))
		fdf_error(EMLX);
}
