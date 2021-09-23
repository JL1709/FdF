/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:24:53 by jludt             #+#    #+#             */
/*   Updated: 2021/09/20 18:51:19 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	error_management(char *s)
{
	int	file;

	file = open(s, O_RDONLY);
	if (file < 0)
		return (pr_error(strerror(errno), s));
	close (file);
	return (0);
}
