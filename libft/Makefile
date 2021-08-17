# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julian <julian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 09:51:20 by jludt             #+#    #+#              #
#    Updated: 2021/08/17 19:55:21 by julian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MANDATORY = ft_atoi.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_putstr_fd.c \
			ft_split.c 

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror *.c
	ar cr $(NAME) *.o

bonus:
	gcc -c -Wall -Wextra -Werror
	ar cr $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re
