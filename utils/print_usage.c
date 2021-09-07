/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:57:28 by jludt             #+#    #+#             */
/*   Updated: 2021/09/07 15:56:51 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
** https://harm-smits.github.io/42docs/libs/minilibx/prototypes
** .html#mlx_string_put
*/

void	print_usage(t_data *data)
{
	char	*s;

	s = "'Esc'      -> Quit program";
	mlx_string_put(data->init, data->win, 10, 5, 0xFFFFFF, s);
	s = "'R'        -> Reset map";
	mlx_string_put(data->init, data->win, 10, 20, 0xFFFFFF, s);
	s = "'+/-'      -> Zoom in/out";
	mlx_string_put(data->init, data->win, 10, 35, 0xFFFFFF, s);
	s = "'up/down'  -> Height up/down";
	mlx_string_put(data->init, data->win, 10, 50, 0xFFFFFF, s);
	s = "'w/s/a/d'  -> Move up/down/left/right";
	mlx_string_put(data->init, data->win, 10, 65, 0xFFFFFF, s);
}
