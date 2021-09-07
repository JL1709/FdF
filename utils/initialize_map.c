/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:56:47 by jludt             #+#    #+#             */
/*   Updated: 2021/09/07 16:32:19 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	initialize_map(t_data *data)
{
	data->scale_depth = 1.00;
	data->angle_x = cos(0.8);
	data->angle_y = sin(0.5);
	data->x_translate = 0;
	data->y_translate = 0;
	data->zoom = ((WINDOW_WIDTH / data->width) \
				+ (WINDOW_HEIGHT / data->height)) / 3;
	data->blue = 0x00;
	data->green = 0x6F + 1;
	data->red = 0x00;
}
