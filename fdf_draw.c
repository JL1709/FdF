/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:34:47 by jludt             #+#    #+#             */
/*   Updated: 2021/08/13 17:11:55 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pixel(t_data *data, int x, int y, double uvector)
{
	int pos;

	if ((x > 0 && y > 0) && (x < WINDOW_WIDTH && y < WINDOW_HEIGHT))
	{
		pos = (x * 4) + (y * WINDOW_WIDTH * 4);
		data->data_addr[pos] = data->red + uvector;
		data->data_addr[pos + 1] = data->green + uvector;
		data->data_addr[pos + 2] = data->blue + uvector;
		data->data_addr[pos + 3] = 0x7F + uvector;
	}
}

static void	draw_lines(t_data *data)
{
	double	x;
	double	y;
	double	delta_x;
	double	delta_y;
	double	uvector;

	x = data->x0;
	y = data->y0;
	delta_x = data->x1 - data->x0;
	delta_y = data->y1 - data->y0;
	uvector = sqrt((pow(delta_x, 2)) + (pow(delta_y, 2)));
	delta_x = delta_x / uvector;
	delta_y = delta_y / uvector;
	while (uvector > 0)
	{
		put_pixel(data, x, y, uvector);
		x += delta_x;
		y += delta_y;
		uvector--;
	}
	
}

static void	draw_vertical(t_data *data, int x, int y)
{
	int	x_3D;
	int	y_3D;

	x_3D = x - data->width / 2;
	y_3D = y - data->height / 2;
	data->x0 = data->angle_x * (x_3D - y_3D) * data->zoom;
	data->y0 = data->angle_y * (x_3D - y_3D) * data->zoom;
	data->y0 -= data->depth[y][x] * data->z;
	data->x1 = data->angle_x * ((x_3D + 1) - y_3D) * data->zoom;
	data->y1 = data->angle_y * ((x_3D + 1) - y_3D) * data->zoom;
	data->y1 -= data->depth[y][x + 1] * data->z;
	data->x0 += (WINDOW_WIDTH / 2) + data->coordinate_x;
	data->x1 += (WINDOW_WIDTH / 2) + data->coordinate_x;
	data->y0 += (WINDOW_HEIGHT / 2) + data->coordinate_y;
	data->y1 += (WINDOW_HEIGHT / 2) + data->coordinate_y;
	draw_lines(data);
}


static void	draw_horizontal(t_data *data, int x, int y)
{
	int	x_3D;
	int	y_3D;

	x_3D = x - data->width / 2;
	y_3D = y - data->height / 2;
	data->x0 = data->angle_x * (x_3D - y_3D) * data->zoom;
	data->y0 = data->angle_y * (x_3D - y_3D) * data->zoom;
	data->y0 -= data->depth[y][x] * data->z;
	data->x1 = data->angle_x * (x_3D - (y_3D + 1)) * data->zoom;
	data->y1 = data->angle_y * (x_3D - (y_3D + 1)) * data->zoom;
	data->y1 -= data->depth[y + 1][x] * data->z;
	data->x0 += (WINDOW_WIDTH / 2) + data->coordinate_x;
	data->x1 += (WINDOW_WIDTH / 2) + data->coordinate_x;
	data->y0 += (WINDOW_HEIGHT / 2) + data->coordinate_y;
	data->y1 += (WINDOW_HEIGHT / 2) + data->coordinate_y;
	draw_lines(data);
}

int			fdf_draw(t_data *data)
{
	int	x; 
	int	y;

	data->img = mlx_new_image(data->init, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->data_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
						&data->size_line, &data->endian);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->x0 = x;
			data->y0 = y;
			if (data->width > x + 1)
				draw_horizontal(data, x, y);
			if (data->height > y + 1)
				draw_vertical(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->init, data->win, data->img, 0, 0);
	mlx_destroy_image(data->init, data->img);
	return(0);
}