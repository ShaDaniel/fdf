#include "fdf.h"

static void		fdf_min_max_z(int coord, t_main *fdf)
{
	if (coord < fdf->map->min_z)
		fdf->map->min_z = coord;
	if (coord > fdf->map->max_z)
		fdf->map->max_z = coord;
}

static void		fdf_parse_width(char **coords, t_main *fdf)
{
	size_t		i;
	int			*tmp_coords;
	uint32_t	*tmp_colours;

	i = 0;
	while (coords[i])
		i++;
	if (fdf->map->height == 0)
		fdf->map->width = i;
	else if (fdf->map->width != i)
		fdf_error(ERECTANG);
	tmp_coords = fdf->map->coords;
	tmp_colours = fdf->map->colours;
	fdf->map->coords = (int *)ft_memalloc((fdf->map->total + fdf->map->width) * sizeof(int));
	fdf->map->colours = (uint32_t *)ft_memalloc((fdf->map->total + fdf->map->width) * sizeof(uint32_t));
	if (!fdf->map->coords || !fdf->map->colours)
		fdf_error(EMEM);
	ft_memcpy(fdf->map->coords, tmp_coords, fdf->map->total * sizeof(int));
	ft_memcpy(fdf->map->colours, tmp_colours, fdf->map->total * sizeof(uint32_t));
	free(tmp_coords);
	free(tmp_colours);
	fdf->map->total += fdf->map->width;
}

static uint32_t	fdf_parse_colour(char *clr)
{
	uint32_t	colour;

	colour = 0;
	if (!clr[0] || !clr[1] || clr[0] != '0' || clr[1] != 'x' || !clr[2])
		fdf_error(ECOLOUR);
	clr += 2;
	while (*clr)
	{
		colour *= 16;
		if (*clr >= '0' && *clr <= '9')
			colour += *clr - '0';
		else if (*clr >= 'a' && *clr <= 'f')
			colour += *clr - 'a' + 10;
		else if (*clr >= 'A' && *clr <= 'F')
			colour += *clr - 'A' + 10;
		else
			fdf_error(ECOLOUR);
		clr++;	
	}
	return (colour);
}

static void		fdf_parse_line(char **coords, t_main *fdf)
{
	char	**coord_colors;
	size_t	i;
	int		coord;

	i = 0;
	fdf_parse_width(coords, fdf);
	while (coords[i])
	{
		coord_colors = ft_strsplit(coords[i], ',');
		if (coord_colors[1])
		{
			fdf->map->origin_colour = 1;
			fdf->map->colours[fdf->map->height * fdf->map->width + i] = fdf_parse_colour(coord_colors[1]);
			if (coord_colors[2])
				fdf_error(ECOLOUR);
		}
		coord = ft_atoi(coord_colors[0]);
		fdf->map->coords[fdf->map->height * fdf->map->width + i] = coord;
		fdf_min_max_z(coord, fdf);
		if (ft_numlen(coord) != ft_strlen(coord_colors[0]))
			fdf_error(ECOORD);
		ft_freechararr(coord_colors);
		i++;
	}
	fdf->map->height++;
}

void			fdf_parse_map(int fd, t_main *fdf)
{
	char	*line;
	char	**coords;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		coords = ft_strsplit(line, ' ');
		fdf_parse_line(coords, fdf);
		ft_strdel(line);
		ft_freechararr(coords);
	}
}
