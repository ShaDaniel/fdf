# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 19:05:22 by tjonella          #+#    #+#              #
#    Updated: 2020/05/14 04:51:36 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

C_FILES = ft_isprint.c ft_memccpy.c ft_putendl.c ft_strcmp.c ft_strlen.c ft_strrchr.c ft_itoa.c ft_memchr.c ft_putendl_fd.c ft_strcpy.c ft_strmap.c ft_strsplit.c ft_lstadd.c ft_memcmp.c ft_putnbr.c ft_strdel.c ft_strmapi.c ft_strstr.c ft_atoi.c ft_lstdel.c ft_memcpy.c ft_putnbr_fd.c ft_strdup.c ft_strncat.c ft_strsub.c ft_bzero.c ft_lstdelone.c	ft_memdel.c	ft_putstr.c	ft_strequ.c	ft_strncmp.c ft_strtrim.c ft_isalnum.c ft_lstiter.c ft_memmove.c ft_putstr_fd.c ft_striter.c ft_strncpy.c ft_tolower.c ft_isalpha.c ft_lstmap.c ft_memset.c ft_strcat.c ft_striteri.c ft_strnequ.c ft_toupper.c ft_isascii.c ft_lstnew.c ft_putchar.c ft_strchr.c ft_strjoin.c ft_strnew.c ft_isdigit.c ft_memalloc.c ft_putchar_fd.c ft_strclr.c ft_strlcat.c	ft_strnstr.c ft_numlen.c ft_strnjoin.c ft_strndup.c get_next_line.c ft_abs.c ft_freechararr.c ft_min.c

O_FILES = *.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(C_FILES) -I $(HEADER)
	ar rc $(NAME) $(O_FILES)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
