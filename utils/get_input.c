/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:39:14 by jludt             #+#    #+#             */
/*   Updated: 2021/09/07 16:34:05 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	get_height(char *src)
{
	int		height;
	int		i;
	char	*str;

	height = 0;
	i = open(src, O_RDONLY);
	str = get_next_line(i);
	while (str)
	{
		free(str);
		str = NULL;
		str = get_next_line(i);
		height++;
	}
	close(i);
	return (height);
}

static int	get_width(char *src)
{
	t_width	h;

	h.width = 0;
	h.i = open(src, O_RDONLY);
	h.str = get_next_line(h.i);
	while (h.str)
	{
		h.j = 0;
		while (h.str[h.j] != '\n' && h.str[h.j] != '\0')
		{
			if (ft_isalnum(h.str[h.j]) == 1 || h.str[h.j] == ',')
			{
				while (ft_isalnum(h.str[h.j]) == 1 || h.str[h.j] == ',')
					h.j++;
				h.width++;
			}
			h.j++;
		}
		break ;
	}
	free(h.str);
	close(h.i);
	return (h.width);
}

static void	get_depth(t_data *data, int x, int y, char *line)
{
	int		i;
	int		j;
	char	**split;

	split = ft_split(line, ' ');
	if (split)
	{
		i = 0;
		while (split[i] && (x != data->width))
		{
			data->depth[y][x] = ft_atoi(split[i++]);
			x++;
		}
		j = -1;
		while (++j < data->width)
			free(split[j]);
		free(split);
	}
}

void	get_input(char *src, t_data *data)
{
	t_read	helper;
	char	*line;

	data->height = get_height(src);
	data->width = get_width(src);
	helper.x = 0;
	helper.y = 0;
	data->depth = (int **)malloc(sizeof(int *) * data->height);
	if (data->depth == NULL)
		return ;
	helper.i = open(src, O_RDONLY);
	line = get_next_line(helper.i);
	while (helper.y != data->height)
	{
		data->depth[helper.y] = (int *)malloc(sizeof(int) * data->width);
		if (data->depth[helper.y] == NULL)
			return ;
		get_depth(data, helper.x, helper.y, line);
		helper.x = 0;
		helper.y++;
		free(line);
		line = get_next_line(helper.i);
	}
	close(helper.i);
}
