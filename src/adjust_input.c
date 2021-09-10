/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:54:32 by jludt             #+#    #+#             */
/*   Updated: 2021/09/10 14:00:31 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	adjust_input(t_data *data)
{
	int	y;
	int	x;
	int	min;

	min = data->min * (-1);
	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
			data->depth[y][x] += min;
	}
}
