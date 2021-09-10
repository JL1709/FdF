/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_gradient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:38:31 by jludt             #+#    #+#             */
/*   Updated: 2021/09/10 13:16:46 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_gradient2(int min, int max)
{
	int	gradient;

	gradient = 0;
	while (min < max)
	{
		gradient++;
		min++;
	}
	return (gradient);
}

void	get_gradient(t_data *data)
{
	int	i;
	int	j;

	data->min = 0;
	data->max = 0;
	data->gradient = 0;
	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
		{
			if (data->depth[i][j] < data->min)
				data->min = data->depth[i][j];
			if (data->depth[i][j] > data->max)
				data->max = data->depth[i][j];
		}
	}
	data->gradient = get_gradient2(data->min, data->max);
}
