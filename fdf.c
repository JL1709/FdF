/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:16:27 by jludt             #+#    #+#             */
/*   Updated: 2021/08/13 16:20:35 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	mlx_loop_hook(data->init, fdf_draw, data);
	mlx_loop(data->init);

	// printf("height = %i\n", data->height);
	// printf("width = %i\n", data->width);
	// y = 0;
	// while (y < data->height)
	// {
	// 	x = 0;
	// 	while (x < data->width)
	// 	{
	// 		printf("%i", data->depth[y][x++]);
	// 		printf(" ");
	// 	}
	// 	printf("\n");
	// 	y++;
	//	}

	//free(data);
	return (0);
}
