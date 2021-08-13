/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:08:57 by julian            #+#    #+#             */
/*   Updated: 2021/08/13 16:17:41 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <math.h>
# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"

# define WINDOW_WIDTH	1280
# define WINDOW_HEIGHT	720

typedef struct s_data
{
	int		height;
	int		width;
	int		**depth;
	int		coordinate_x;
	int		coordinate_y;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	double	angle_x;
	double	angle_y;
	double	z;
	int		zoom;
	int		isometric;

	void	*init;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	int		red;
	int		green;
	int		blue;
	
}			t_data;

void	fdf_read(char *src, t_data *data);
int		fdf_draw(t_data *data);
void	initialize_map(t_data *data);

#endif