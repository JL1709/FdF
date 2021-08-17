/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:34:47 by jludt             #+#    #+#             */
/*   Updated: 2021/08/17 13:49:14 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pixel(t_data *data)
{
	int	pos;
	int	x;
	int	y;

	x = data->x0;
	y = data->y0;

	if ((x > 0 && y > 0) && (x < WINDOW_WIDTH && y < WINDOW_HEIGHT))
	{
		pos = y * data->size_line + x * (data->bits_per_pixel / 8);
		data->data_addr[pos] = data->red;
		data->data_addr[pos + 1] = data->green;
		data->data_addr[pos + 2] = data->blue;
	}
}

/*
** https://de.wikipedia.org/wiki/Bresenham-Algorithmus
*/

static void	bresenham(t_data *data)
{
	initialize_bresenham(data);
	while (1) 
	{
		put_pixel(data);
		if (data->x0 == data->x1 && data->y0 == data->y1) 
			break;
		data->e2 = 2 * data->err;
		if (data->e2 > data->dy) 
		{
			data->err += data->dy; 
			data->x0 += data->sx; 
		}
		if (data->e2 < data->dx) 
		{
			data->err += data->dx; 
			data->y0 += data->sy; 
		}
  }
}

/*
**	isometric projection:
**	- change coordinates by using isometric formulas:
**		x` = (x - y) * cos(angle)
**		y` = (x + y) * sin(angle) - z
**	- x` and y` are coordinates in 3D format
*/

static void	isometric_vertical(t_data *data, int x, int y)
{
	int	x_centered;
	int	y_centered;

	x_centered = x - data->width / 2;
	y_centered = y - data->height / 2;
	data->x0 = (x_centered - y_centered) * data->angle_x * data->zoom \
				+ (WINDOW_WIDTH / 2);
	data->y0 = (x_centered + y_centered) * data->angle_y * data->zoom \
				- data->depth[y][x] * data->scale_depth \
				+ (WINDOW_HEIGHT / 2);
	data->x1 = (x_centered - (y_centered + 1)) * data->angle_x * data->zoom \
				+ (WINDOW_WIDTH / 2);
	data->y1 = (x_centered + (y_centered + 1)) * data->angle_y * data->zoom \
				- data->depth[y + 1][x] * data->scale_depth \
				+ (WINDOW_HEIGHT / 2);
	bresenham(data);
}

static void	isometric_horizontal(t_data *data, int x, int y)
{
	int	x_centered;
	int	y_centered;

	x_centered = x - data->width / 2;
	y_centered = y - data->height / 2;
	data->x0 = (x_centered - y_centered) * data->angle_x * data->zoom \
				+ (WINDOW_WIDTH / 2);
	data->y0 = (x_centered + y_centered) * data->angle_y * data->zoom \
				- data->depth[y][x] * data->scale_depth \
				+ (WINDOW_HEIGHT / 2);
	data->x1 = ((x_centered + 1) - y_centered) * data->angle_x * data->zoom \
				+ (WINDOW_WIDTH / 2);
	data->y1 = ((x_centered + 1) + y_centered) * data->angle_y * data->zoom \
				- data->depth[y][x + 1] * data->scale_depth \
				+ (WINDOW_HEIGHT / 2);
	bresenham(data);
}

int			fdf_draw(t_data *data)
{
	int	x; 
	int	y;

	data->img = mlx_new_image(data->init, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->data_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
						&data->size_line, &data->endian);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->x0 = x;
			data->y0 = y;
			if (x < data->width - 1)
				isometric_horizontal(data, x, y);
			if (y < data->height - 1)
				isometric_vertical(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->init, data->win, data->img, 0, 0);
	mlx_destroy_image(data->init, data->img);
	return(0);
}