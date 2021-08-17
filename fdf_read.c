/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:39:14 by jludt             #+#    #+#             */
/*   Updated: 2021/08/17 20:02:50 by julian           ###   ########.fr       */
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
			if (ft_isalnum(*str) == 1 || *str == ',')
			{
				while (ft_isalnum(*str) == 1 || *str == ',')
					str++;
				width++;
			}
			str++;
		}
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
	if (data->depth == NULL)
		return ;
	i = open(src, O_RDONLY);
	while ((line = get_next_line(i)) && y != data->height)
	{
		data->depth[y] = (int *)malloc(sizeof(int) * data->width);
		if (data->depth[y] == NULL)
			return ;
		get_depth(data, x, y, line);
		x = 0;
		y++;
		free(line);
	}
	close(i);
}
