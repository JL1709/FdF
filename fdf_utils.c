/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:30:31 by julian            #+#    #+#             */
/*   Updated: 2021/08/26 19:22:08 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_map(t_data *data)
{
	data->scale_depth = 1.00;
	data->angle_x = cos(0.6);
	data->angle_y = sin(0.4);
	data->x_translate = 0;
	data->y_translate = 0;
	data->zoom = ((WINDOW_WIDTH / data->width) \
				+ (WINDOW_HEIGHT / data->height)) / 3;
	data->blue = 0x00;
	data->green = 0x6F;
	data->red = 0x00;
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

int		fdf_interactive(int key, t_data *data)
{	
	if (key == 0x35)
		exit(0);
	else if (key == 0x0F)
		initialize_map(data);
	else if (key == 0x45)
		data->zoom += 1;
	else if (key == 0x4E)
		data->zoom -= 1;
	else if (key == 0x00)
		data->x_translate += 10;
	else if (key == 0x02)
		data->x_translate -= 10;
	else if (key == 0x0D)
		data->y_translate += 10;
	else if (key == 0x01)
		data->y_translate -= 10;
	else if (key == 0x7D)
		data->scale_depth -= 1;
	else if (key == 0x7E)
		data->scale_depth += 1;
	return (0);
}

void	print_usage(t_data *data)
{
	char	*s;

	s = "'Esc'      -> Quit program";
	mlx_string_put(data->init, data->win, 10, 5, 0xFFFFFF, s);
	s = "'R'        -> Reset map";
	mlx_string_put(data->init, data->win, 10, 20, 0xFFFFFF, s);
	s = "'+/-'      -> Zoom in/out";
	mlx_string_put(data->init, data->win, 10, 35, 0xFFFFFF, s);
	s = "'up/down'  -> Height up/down";
	mlx_string_put(data->init, data->win, 10, 50, 0xFFFFFF, s);
	s = "'w/s/a/d'  -> Move up/down/left/right";
	mlx_string_put(data->init, data->win, 10, 65, 0xFFFFFF, s);
}
