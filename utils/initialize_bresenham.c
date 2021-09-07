/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bresenham.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:56:28 by jludt             #+#    #+#             */
/*   Updated: 2021/09/06 16:56:41 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
