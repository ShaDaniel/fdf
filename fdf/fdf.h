#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdint.h>
# include "libft/libft.h"
# include "mlx.h"
# include "gnl/get_next_line.h"
# include <stdio.h>

# define PRG_NAME	"Tjonella's FDF"
# define WIN_HGHT	600
# define WIN_WID	800

# define ZOOM_MIN	1
# define ZOOM_MAX	10
# define DIST_MIN	16

# define EUSE		"usage: ./fdf [map.fdf]\n"
# define ECOORD		"fdf: map coordinates must be a decimal value\n"
# define ERECTANG	"fdf: map coordinates must remain a rectangular shape\n"
# define ECOLOUR	"fdf: colour add: [COORDS,0x****]\n"
# define EMEM		"fdf: memory allocation error\n"
# define EOPEN		"fdf: map file open error\n"
# define EMLX		"fdf: mlx error\n"

# define WHITE		0x00FFFFFF

typedef struct	s_point
{
	size_t		x;
	size_t		y;
	size_t		z;
	uint32_t	colour;
}				t_point;

typedef struct	s_offset
{
	size_t		x;
	size_t		y;
}				t_offset;

typedef struct	s_map
{
	size_t		width;
	size_t		height;
	size_t		total;
	int			*coords;
	uint32_t	*colours;
	char		origin_colour;
	double		zoom;
}				t_map;

typedef struct	s_main
{
	t_map		*map;
	t_offset	*offset;
	void		*mlx;
	void		*win;
	void		*img_init;
	void		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_main;

void			fdf_parse_map(int fd, t_main *fdf);
void			fdf_error(char *error);
void			fdf_init(t_main **fdf);
void			fdf_draw_img(t_main *fdf);

#endif
