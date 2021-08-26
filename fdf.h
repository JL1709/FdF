/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:08:57 by julian            #+#    #+#             */
/*   Updated: 2021/08/26 19:10:26 by julian           ###   ########.fr       */
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
	void	*init;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	
	int		height;
	int		width;
	int		**depth;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		x_translate;
	int		y_translate;
	float	angle_x;
	float	angle_y;
	int		scale_depth;
	int		zoom;

	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;

	int		red;
	int		green;
	int		blue;
	
}			t_data;

void	fdf_read(char *src, t_data *data);
int		fdf_draw(t_data *data);
void	initialize_map(t_data *data);
void	initialize_bresenham(t_data *data);
int		fdf_interactive(int key, t_data *data);
void	print_usage(t_data *data);

#endif