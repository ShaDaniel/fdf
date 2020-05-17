/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 20:56:11 by marvin            #+#    #+#             */
/*   Updated: 2020/05/17 22:37:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	get_index_last_coords(char **coords)
{
	size_t i;

	i = 0;
	while (coords[i])
		i++;
	return (i);
}

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

	i = get_index_last_coords(coords);
	if (fdf->map->height == 0)
		fdf->map->width = i;
	else if (fdf->map->width != i)
		fdf_error(ERECTANG);
	tmp_coords = fdf->map->coords;
	tmp_colours = fdf->map->colours;
	fdf->map->coords = (int *)ft_memalloc((fdf->map->total +
		fdf->map->width) * sizeof(int));
	fdf->map->colours = (uint32_t *)ft_memalloc((fdf->map->total +
		fdf->map->width) * sizeof(uint32_t));
	if (!fdf->map->coords || !fdf->map->colours)
		fdf_error(EMEM);
	ft_memcpy(fdf->map->coords, tmp_coords,
		fdf->map->total * sizeof(int));
	ft_memcpy(fdf->map->colours, tmp_colours,
		fdf->map->total * sizeof(uint32_t));
	free(tmp_coords);
	free(tmp_colours);
	fdf->map->total += fdf->map->width;
}

static void		fdf_parse_line(char **coords, t_main *fdf)
{
	char	**coord_colors;
	int		i;
	int	 	coord;

	i = -1;
	fdf_parse_width(coords, fdf);
	while (coords[++i])
	{
		coord_colors = ft_strsplit(coords[i], ',');
		if (coord_colors[1])
		{
			fdf->map->origin_colour = 1;
			fdf->map->colours[fdf->map->height * fdf->map->width + i] =
				fdf_parse_colour(coord_colors[1]);
			if (coord_colors[2])
				fdf_error(ECOLOUR);
		}
		coord = ft_atoi(coord_colors[0]);
		fdf->map->coords[fdf->map->height * fdf->map->width + i] = coord;
		fdf_min_max_z(coord, fdf);
		if (ft_numlen(coord) != ft_strlen(coord_colors[0]))
			fdf_error(ECOORD);
		ft_freechararr(coord_colors);
	}
	fdf->map->height++;
}

void			fdf_parse_map(int fd, t_main *fdf)
{
	char	*line;
	char	**coords;
	int		check_gnl;

	line = NULL;
	while ((check_gnl = get_next_line(fd, &line)) > 0)
	{
		coords = ft_strsplit(line, ' ');
		fdf_parse_line(coords, fdf);
		ft_strdel(line);
		ft_freechararr(coords);
	}
	if (check_gnl == -1)
		fdf_error(EMEM);
}
