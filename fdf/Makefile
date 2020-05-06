NAME = fdf

SRC =		main.c\
			fdf_init.c\
			fdf_parse_map.c\
			fdf_error.c

HEADERS =	fdf.h

OBJ = $(SRC:.c=.o)

LIBFT = 	libft.a
DIR_LIBFT =	./libft/

CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(DIR_LIBFT)

$(NAME): $(LIBFT)
	gcc -c $(SRC)
	gcc -o $(NAME) $(OBJ) -I $(HEADERS) -L $(DIR_LIBFT) -lft
