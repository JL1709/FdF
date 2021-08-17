/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:30:31 by julian            #+#    #+#             */
/*   Updated: 2021/08/17 20:19:19 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_map(t_data *data)
{
	data->scale_depth = 1.00;
	data->angle_x = cos(0.6);
	data->angle_y = sin(0.4);
	data->zoom = ((WINDOW_WIDTH / data->width) \
				+ (WINDOW_HEIGHT / data->height)) / 3;
	data->red = 0x00;
	data->green = 0x6F;
	data->blue = 0x00;
}

void	initialize_bresenham(t_data *data)
{
	data->dx = abs(data->x1 - data->x0);
	if (data->x0 < data->x1)
		data->sx = 1; 
	else	
		data->sx = -1;
	data->dy = -abs(data->y1 - data->y0);
	if (data->y0 < data->y1)
		data->sy = 1;
	else
		data->sy = -1;
	data->err = data->dx + data->dy;
}

int		fdf_exit(int key, t_data *data)
{
	(void)	data;
	
	if (key == 0x35)
		exit(0);
	return (0);
}