# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/17 20:55:49 by marvin            #+#    #+#              #
#    Updated: 2020/05/17 22:32:09 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =		main.c\
			fdf_init.c\
			fdf_parse_map.c\
			fdf_error.c\
			fdf_draw_img.c\
			fdf_hooks.c\
			fdf_colours.c

HEADERS =	-I inc/ -I $(DIR_LIBFT) -I $(DIR_MLX)

OBJ = $(addprefix $(DIR_OBJ), $(SRC:.c=.o))
DIR_SRC = src/
DIR_OBJ = obj/

LIBFT = 	libft.a
DIR_LIBFT =	./libft/
DIR_MLX = ./minilibx_macos/

CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(DIR_LIBFT)

mlx:
	make -C $(DIR_MLX)

$(DIR_OBJ):
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ)%.o: $(DIR_SRC)%.c inc/fdf.h
	gcc $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(LIBFT) mlx $(DIR_OBJ) $(OBJ)
	gcc -o $(NAME) $(OBJ) -L $(DIR_LIBFT) -lft -L $(DIR_MLX) -lmlx -framework OpenGL -framework AppKit

clean:
	rm -rf $(DIR_OBJ)
	make clean -C $(DIR_LIBFT)
	make clean -C $(DIR_MLX)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(DIR_LIBFT)

re: fclean all
	