# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julian <julian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 09:51:20 by jludt             #+#    #+#              #
#    Updated: 2022/01/02 17:30:09 by julian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MANDATORY = ft_atoi.c		\
			ft_callo.c		\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isdigit.c	\
			ft_putstr.c		\
			ft_split.c		\
			ft_strchr.c		\
			ft_strjoin.c	\
			ft_strlen.c		\
			get_next_line.c	\

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror *.c
	@ar cr $(NAME) *.o

bonus:
	@gcc -c -Wall -Wextra -Werror
	@ar cr $(NAME) *.o

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re
