/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:13:25 by jludt             #+#    #+#             */
/*   Updated: 2021/09/09 18:14:22 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			n_bzero;
	int				i;

	ptr = malloc(count * size);
	n_bzero = count * size;
	if (ptr != 0)
	{
		i = 0;
		while (n_bzero-- > 0)
			ptr[i++] = '\0';
		return (ptr);
	}
	return (0);
}
