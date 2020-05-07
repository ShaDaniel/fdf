NAME = fdf

SRC =		main.c\
			fdf_init.c\
			fdf_parse_map.c\
			fdf_error.c

HEADERS =	fdf.h

OBJ = $(SRC:.c=.o)

LIBFT = 	libft.a
DIR_LIBFT =	./libft/
DIR_MLX = ./minilibx_macos/

CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(DIR_LIBFT)

mlx:
	make -C $(DIR_MLX)

$(NAME): $(LIBFT) mlx
	gcc -c $(SRC)
	gcc -o $(NAME) $(OBJ) -I $(HEADERS) -L $(DIR_LIBFT) -lft -L $(DIR_MLX) -lmlx -framework OpenGL -framework AppKit
