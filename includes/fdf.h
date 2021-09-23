/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:08:57 by julian            #+#    #+#             */
/*   Updated: 2021/09/23 09:14:20 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <math.h>
# include <errno.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

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

	int		min;
	int		max;
	int		gradient;
}			t_data;

typedef struct s_read
{
	int	i;
	int	x;
	int	y;
}			t_read;

typedef struct s_width
{
	int		i;
	int		j;
	int		width;
	char	*str;
}			t_width;

int		pr_error(char *s1, char *s2);
int		error_management(char *s);
void	get_input(char *src, t_data *data);
void	get_gradient(t_data *data);
void	adjust_input(t_data *data);
int		draw_image(t_data *data);
void	initialize_map(t_data *data);
void	initialize_bresenham(t_data *data);
int		interactive(int key, t_data *data);
void	print_usage(t_data *data);
void	free_data(t_data *data);

#endif