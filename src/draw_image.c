/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:34:47 by jludt             #+#    #+#             */
/*   Updated: 2021/09/10 14:00:52 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
*/

static void	put_pixel(t_data *data, int x_grad, int y_grad, int direction)
{
	int		offset;
	int		x;
	int		y;
	float	gradient;

	gradient = (float)data->depth[y_grad][x_grad] / data->gradient;
	if (gradient == 0 && direction == 1)
		if (data->depth[y_grad][x_grad] < data->depth[y_grad][x_grad + 1])
			gradient = (float)data->depth[y_grad][x_grad + 1] / data->gradient;
	if (gradient == 0 && direction == 2)
		if (data->depth[y_grad][x_grad] < data->depth[y_grad + 1][x_grad])
			gradient = (float)data->depth[y_grad + 1][x_grad] / data->gradient;
	x = data->x0;
	y = data->y0;
	if ((x > 0 && y > 0) && (x < WINDOW_WIDTH && y < WINDOW_HEIGHT))
	{
		offset = y * data->size_line + x * (data->bits_per_pixel / 8);
		data->data_addr[offset] = data->blue;
		data->data_addr[offset + 1] = data->green * gradient;
		data->data_addr[offset + 2] = data->red;
	}
}

/*
** https://de.wikipedia.org/wiki/Bresenham-Algorithmus
*/

static void	bresenham(t_data *data, int x, int y, int direction)
{
	initialize_bresenham(data);
	while (1)
	{
		put_pixel(data, x, y, direction);
		if (data->x0 == data->x1 && data->y0 == data->y1)
			break ;
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
** http://www.gandraxa.com/isometric_projection.xml
** isometric projection:
** x` = (x - y) * cos(α)
** y` = (x + y) * sin(α) - z
*/

static void	isometric_vertical(t_data *data, int x, int y)
{
	int	xc;
	int	yc;

	xc = x - data->width / 2;
	yc = y - data->height / 2;
	data->x0 = (xc - yc) * data->angle_x * data->zoom \
				+ (WINDOW_WIDTH / 2) + data->x_translate;
	data->y0 = (xc + yc) * data->angle_y * data->zoom \
				- data->depth[y][x] * data->scale_depth \
				+ (WINDOW_HEIGHT / 2) + data->y_translate;
	data->x1 = (xc - (yc + 1)) * data->angle_x * data->zoom \
				+ (WINDOW_WIDTH / 2) + data->x_translate;
	data->y1 = (xc + (yc + 1)) * data->angle_y * data->zoom \
				- data->depth[y + 1][x] * data->scale_depth \
				+ (WINDOW_HEIGHT / 2) + data->y_translate;
	bresenham(data, x, y, 2);
}

static void	isometric_horizontal(t_data *data, int x, int y)
{
	int	xc;
	int	yc;

	xc = x - data->width / 2;
	yc = y - data->height / 2;
	data->x0 = (xc - yc) * data->angle_x * data->zoom \
				+ (WINDOW_WIDTH / 2) + data->x_translate;
	data->y0 = (xc + yc) * data->angle_y * data->zoom \
				- data->depth[y][x] * data->scale_depth \
				+ (WINDOW_HEIGHT / 2) + data->y_translate;
	data->x1 = ((xc + 1) - yc) * data->angle_x * data->zoom \
				+ (WINDOW_WIDTH / 2) + data->x_translate;
	data->y1 = ((xc + 1) + yc) * data->angle_y * data->zoom \
				- data->depth[y][x + 1] * data->scale_depth \
				+ (WINDOW_HEIGHT / 2) + data->y_translate;
	bresenham(data, x, y, 1);
}

/*
** https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
*/

int	draw_image(t_data *data)
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
			if (x < data->width - 1)
				isometric_horizontal(data, x, y);
			if (y < data->height - 1)
				isometric_vertical(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->init, data->win, data->img, 0, 0);
	print_usage(data);
	mlx_destroy_image(data->init, data->img);
	return (0);
}
