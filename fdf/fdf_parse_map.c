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
	ft_putstr("----------------");
	if (fdf->map->height == 0)
		fdf->map->width = i;
	else if (fdf->map->width != i)
		fdf_error(ERECTANG);
	ft_putstr("************");
	new_coords = (int *)ft_memalloc(fdf->map->total * sizeof(int) + fdf->map->width);
	ft_putstr("&&&&&&&&&&");
	new_colours = (uint32_t *)ft_memalloc(fdf->map->total * sizeof(uint32_t) + fdf->map->width);
	if (!new_coords || !new_colours)
		fdf_error(EMEM);
		
	ft_putstr("UUUUUUUUUUUUUUUU");
	ft_memcpy(new_coords, fdf->map->coords, fdf->map->total * sizeof(int));
	ft_memcpy(new_colours, fdf->map->colours, fdf->map->total * sizeof(uint32_t));
	//free(fdf->map->coords);
	//free(fdf->map->colours);
	fdf->map->coords = new_coords;
	fdf->map->colours = new_colours;
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
	printf("THIS ALWAYS WORKS");
	printf("%s!!", coords[0]);
	fdf_parse_width(coords, fdf);
	printf("zzzzzzz\n");
	while (coords[i])
	{
		printf("%s qqqqqqq\n", coords[i]);
		coord_colors = ft_strsplit(coords[i], ',');
		ft_putstr("____________");
		if (coord_colors && coord_colors[0])
			ft_putstr(coord_colors[0]);
		if (coord_colors[1])
		{
			fdf->map->origin_colour = 1;
			fdf->map->colours[fdf->map->height * fdf->map->width + i] = fdf_parse_colour(coord_colors[1]);
			if (coord_colors[2])
				fdf_error(ECOLOUR);
		}
		ft_putstr("|");
		coord = ft_atoi(coord_colors[0]);
		ft_putnbr(coord);
		fdf->map->coords[fdf->map->height * fdf->map->width + i] = coord;
		ft_putstr("$$$$$");
		ft_putnbr(ft_strlen(coord_colors[0]));
		ft_putstr(coord_colors[0]);
		if (ft_numlen(coord) != ft_strlen(coord_colors[0]))
			fdf_error(ECOORD);
		//printf(" %lu ", i);
		//free(coord_colors[0]);
		//free(coord_colors[1]);
		//free(coord_colors);
		//free2darr
		fdf->map->height++;
		i++;
	}
}

void			fdf_parse_map(int fd, t_main *fdf)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		if (line && *line)
			fdf_parse_line(ft_strsplit(line, ' '), fdf);
		//free(line);
		line = NULL;
	}
}
