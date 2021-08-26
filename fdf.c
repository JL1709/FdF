/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:16:27 by jludt             #+#    #+#             */
/*   Updated: 2021/08/26 18:46:40 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
		return (0);
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (0);
	fdf_read(argv[1], data);	
	initialize_map(data);
	data->init = mlx_init();
	data->win = mlx_new_window(data->init, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	mlx_hook(data->win, 2, 3, fdf_interactive, data);
	mlx_loop_hook(data->init, fdf_draw, data);
	mlx_loop(data->init);
	free(data);
	return (0);
}
