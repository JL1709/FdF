/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:55:49 by jludt             #+#    #+#             */
/*   Updated: 2021/09/09 18:25:50 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_data(t_data *data)
{
	int	y;

	y = -1;
	while (++y < data->height)
		free(data->depth[y]);
	free(data->depth);
	free(data);
}
