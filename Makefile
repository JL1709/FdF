# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julian <julian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 12:13:12 by jludt             #+#    #+#              #
#    Updated: 2021/08/17 13:31:26 by julian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

MLXPATH = ./mlx/libmlx.a

LIBFTPATH = ./libft/libft.a


CFLAGS = -Wall -Werror -Wextra $(MLXPATH) $(LIBFTPATH) -framework OpenGL -framework AppKit

CFILES =	fdf.c \
			fdf_read.c \
			fdf_draw.c \
			fdf_utils.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c 

OBJECTS = $(CFILES:.c=.o)

$(NAME):
	make --directory=./mlx
	make --directory=./libft
	$(CC) $(CFILES) $(CFLAGS) -o $(NAME)

clean: 
	rm -f $(OBJECTS)
	make clean --directory=./libft
	make clean --directory=./mlx

fclean:
	rm -f $(NAME) $(OBJECTS)
	make fclean --directory=./libft
	make clean --directory=./mlx

re: fclean $(NAME)
	make re --directory=./libft
	make re --directory=./mlx
