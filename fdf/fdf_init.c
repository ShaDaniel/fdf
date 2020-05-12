#include "fdf.h"

void	fdf_init(t_main **fdf)
{
	if (!(*fdf = (t_main *)ft_memalloc(sizeof(t_main))))
		fdf_error(EMEM);
	if (!((*fdf)->map = (t_map *)ft_memalloc(sizeof(t_map))))
		fdf_error(EMEM);
	if (!((*fdf)->offset = (t_offset *)ft_memalloc(sizeof(t_offset))))
		fdf_error(EMEM);
	
	(*fdf)->map->width = 0;
	(*fdf)->map->height = 0;
	(*fdf)->map->total = 0;
	(*fdf)->map->colours = NULL;
	(*fdf)->map->coords = NULL;
	(*fdf)->offset->x = 100;
	(*fdf)->offset->y = 100;
	
	(*fdf)->map->zoom = 4;
	if (!((*fdf)->mlx = mlx_init()))
		fdf_error(EMLX);
	if (!((*fdf)->win = mlx_new_window((*fdf)->mlx, WIN_WID, WIN_HGHT, PRG_NAME)))
		fdf_error(EMLX);
	if (!((*fdf)->img = mlx_new_image((*fdf)->mlx, WIN_WID, WIN_HGHT)))
		fdf_error(EMLX);
	if (!((*fdf)->data_addr = mlx_get_data_addr((*fdf)->img, &((*fdf)->bits_per_pixel), &((*fdf)->size_line), &((*fdf)->endian))))
		fdf_error(EMLX);
}
