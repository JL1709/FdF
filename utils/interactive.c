/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:55:16 by jludt             #+#    #+#             */
/*   Updated: 2021/09/07 16:35:05 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
** https://stackoverflow.com/questions/3202629/where-can-i-find-a-list-of
** -mac-virtual-key-codes/16125341#16125341
** https://developer.apple.com/library/archive/documentation/mac/pdf/
** MacintoshToolboxEssentials.pdf --> Figure 2-10
** --> for US keyboard layout
*/

int	interactive(int key, t_data *data)
{	
	if (key == 0x35)
	{
		free_data(data);
		exit(0);
	}
	else if (key == 0x0F)
		initialize_map(data);
	else if (key == 0x45)
		data->zoom += 1;
	else if (key == 0x4E)
		data->zoom -= 1;
	else if (key == 0x00)
		data->x_translate += 10;
	else if (key == 0x02)
		data->x_translate -= 10;
	else if (key == 0x0D)
		data->y_translate += 10;
	else if (key == 0x01)
		data->y_translate -= 10;
	else if (key == 0x7D)
		data->scale_depth -= 1;
	else if (key == 0x7E)
		data->scale_depth += 1;
	return (0);
}
