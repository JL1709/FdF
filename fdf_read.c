/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:39:14 by jludt             #+#    #+#             */
/*   Updated: 2021/08/13 13:47:11 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_height(char *src)
{
	int		height;
	int		i;
	char	*str;

	height = 0;
	i = open(src, O_RDONLY);
	while ((str = get_next_line(i)))
		height++;
	close(i);
	return (height);
}

static int	get_width(char *src)
{
	int		width;
	int		i;
	char	*str;

	width = 0;
	i = open(src, O_RDONLY);
	while ((str = get_next_line(i)))
	{
		while (*str != '\n' && *str != '\0')
		{
			if (*str == ' ' && *(str + 1) == '-' && ft_isdigit(*(str + 2)) == 1)
				width++;
			else if (*str == ' ' && ft_isdigit(*(str + 1)) == 1)
				width++;
			str++;
		}
		width++;
		break ;
	}
	close(i);
	return (width);
}

static void	get_depth(t_data *data, int x, int y, char *line)
{
	int		i;
	char	**split;

	if ((split = ft_split(line, ' ')))
	{
		i = 0;
		while (split[i] && (x != data->width))
		{
			data->depth[y][x] = ft_atoi(split[i++]);
			x++;
		}
		free(split);
	}
}

void	fdf_read(char *src, t_data *data)
{
	int		i;
	int		x;
	int		y;
	char	*line;

	data->height = get_height(src);
	data->width = get_width(src);
	x = 0;
	y = 0;
	data->depth = (int **)malloc(sizeof(int *) * data->height);
	// if (data->depth == NULL)
	// 	return (NULL);
	i = open(src, O_RDONLY);
	while ((line = get_next_line(i)) && y != data->height)
	{
		data->depth[y] = (int *)malloc(sizeof(int) * data->width);
		// if (data->width == NULL)
		// 	return (NULL);
		get_depth(data, x, y, line);
		x = 0;
		y++;
		free(line);
	}
	close(i);
}
