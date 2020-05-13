#include "fdf.h"

static void		fdf_parse_width(char **coords, t_main *fdf)
{
	size_t		i;
	int			*new_coords;
	uint32_t	*new_colours;

	i = 0;
	while (*coords)
	{
		coords++;
		i++;
	}
	if (fdf->map->height == 0)
		fdf->map->width = i;
	else if (fdf->map->width != i)
		fdf_error(ERECTANG);
	new_coords = (int *)ft_memalloc(fdf->map->total * sizeof(int) + fdf->map->width);
	new_colours = (uint32_t *)ft_memalloc(fdf->map->total * sizeof(uint32_t) + fdf->map->width);
	if (!new_coords || !new_colours)
		fdf_error(EMEM);
	ft_memcpy(new_coords, fdf->map->coords, fdf->map->total * sizeof(int));
	ft_memcpy(new_colours, fdf->map->colours, fdf->map->total * sizeof(uint32_t));
	free(fdf->map->coords);
	free(fdf->map->colours);
	fdf->map->coords = new_coords;
	fdf->map->colours = new_colours;
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
	ft_putstr("OK_2?");
	fdf_parse_width(coords, fdf);
	while (coords[i])
	{
		ft_putstr("OK_3?");
		coord_colors = ft_strsplit(coords[i], ',');
		ft_putstr("!!!");
		if (coord_colors[1])
		{
			fdf->map->origin_colour = 1;
			fdf->map->colours[fdf->map->height * fdf->map->width + i] = fdf_parse_colour(coord_colors[1]);
			if (coord_colors[2])
				fdf_error(ECOLOUR);
		}
		coord = ft_atoi(coord_colors[0]);
		fdf->map->coords[fdf->map->height * fdf->map->width + i] = coord;
		ft_putstr("~~~");
		if (i % 18 == 0)
			ft_putchar('\n');
		if (ft_numlen(coord) != ft_strlen(coord_colors[0]))
			fdf_error(ECOORD);
		//ft_freechararr(coord_colors);
		ft_putstr("FREEEEEEEEE");
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
		ft_putstr(line);
		ft_putstr("OK_1?");
		coords = ft_strsplit(line, ' ');
		fdf_parse_line(coords, fdf);
		ft_strdel(&line);
		ft_freechararr(coords);
	}
}
