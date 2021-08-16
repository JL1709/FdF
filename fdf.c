/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:16:27 by jludt             #+#    #+#             */
/*   Updated: 2021/08/15 16:24:16 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		x;
	int		y;

	if (argc != 2)
		return (0);
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (0);
	fdf_read(argv[1], data);
	//printf("test1\n");
	initialize_map(data);
	//printf("test2\n");
	data->init = mlx_init();
	///printf("test3\n");
	data->win = mlx_new_window(data->init, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	//printf("test4\n");
	mlx_loop_hook(data->init, fdf_draw, data);
	//printf("test5\n");
	mlx_loop(data->init);

	printf("height = %i\n", data->height);
	printf("width = %i\n", data->width);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			printf("%i", data->depth[y][x++]);
			printf(" ");
		}
		printf("\n");
		y++;
		}

	free(data);
	return (0);
}
