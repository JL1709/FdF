/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:55:43 by jludt             #+#    #+#             */
/*   Updated: 2021/08/16 09:14:06 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data_addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	initialize_map(t_data *data)
{
	data->coordinate_x = 0;
	data->coordinate_y = 0;
	data->z = 1.00;
	data->angle_x = cos(M_PI / 3);
	data->angle_y = data->angle_x * sin(M_PI / 6);
	if (ceil((data->width > data->height)))
		data->zoom = (WINDOW_WIDTH / data->width) + 2;
	else
		data->zoom = (WINDOW_HEIGHT / data->height) + 2;
	data->isometric = 1;
	data->red = 0x4F;
	data->green = 0x4F;
	data->blue = 0x4F;
}