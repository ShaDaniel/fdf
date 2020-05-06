#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdint.h>
# include "libft/libft.h"
# include "mlx.h"

# define PRG_NAME	"Tjonella's FDF"
# define WIN_HGHT	1366
# define WIN_WID	768

# define EUSE		"usage: ./fdf [map.fdf]"
# define ECOORD		"fdf: map coordinates must be a decimal value"
# define ERECTANG	"fdf: map coordinates must remain a rectangular shape"
# define ECOLOUR	"fdf: colour add: [COORDS,0x****]"
# define EMEM		"fdf: memory allocation error"
# define EOPEN		"fdf: map file open error"
# define EMLX		"fdf: mlx error"

typedef struct	s_offset
{
	int	x;
	int	y;
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
	void		*img_mem;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_main;

void			fdf_parse_map(int fd, t_main *fdf);
void			fdf_error(char *error);
void			fdf_init(t_main **fdf);

#endif