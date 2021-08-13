/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:40:57 by julian            #+#    #+#             */
/*   Updated: 2021/07/21 18:44:24 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s_join;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s_join = (char *)malloc(sizeof(*s1) * (len_s1 + len_s2) + 1);
	if (s_join == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s_join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		s_join[i++] = s2[j++];
	s_join[i] = '\0';
	free(s1);
	return (s_join);
}
