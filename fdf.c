/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:16:27 by jludt             #+#    #+#             */
/*   Updated: 2021/09/07 16:38:21 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*
** https://harm-smits.github.io/42docs/libs/minilibx
*/

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
		return (0);
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (0);
	get_input(argv[1], data);
	initialize_map(data);
	data->init = mlx_init();
	data->win = mlx_new_window(data->init, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	mlx_loop_hook(data->init, draw_image, data);
	mlx_hook(data->win, 2, 1L << 0, interactive, data);
	mlx_loop(data->init);
	free_data(data);
	return (0);
}
